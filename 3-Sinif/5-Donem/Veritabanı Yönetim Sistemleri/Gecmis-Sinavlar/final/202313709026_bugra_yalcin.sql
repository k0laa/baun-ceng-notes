----------------------------------------------------------------------
--PROJE: Atari Konsolu Yönetimi 
----------------------------------------------------------------------



CREATE DATABASE AtariConsole;
GO
USE AtariConsole;



----------------------------------------------------------------------
--TABLOLARI OLUÞTURMA  /  Kategoriler - Oyuncular - Oyunlar - Skorlar
----------------------------------------------------------------------



CREATE TABLE Kategoriler (
    KategoriID INT PRIMARY KEY IDENTITY(1,1),
    KategoriAdi NVARCHAR(50) NOT NULL,
    ZorlukSeviyesi INT -- 1: Çok Kolay, 5: Çok Zor
);

CREATE TABLE Oyuncular (
    OyuncuID INT PRIMARY KEY IDENTITY(1,1),
    TakmaAd NVARCHAR(30) UNIQUE NOT NULL,
    KayitTarihi DATETIME DEFAULT GETDATE(),
    ToplamJeton INT DEFAULT 0
);

CREATE TABLE Oyunlar (
    OyunID INT PRIMARY KEY IDENTITY(1,1),
    OyunAdi NVARCHAR(50) NOT NULL,
    KategoriID INT,
    CikisYili INT,
    --referans
    FOREIGN KEY (KategoriID) REFERENCES Kategoriler(KategoriID)
);

CREATE TABLE Skorlar (
    SkorID INT PRIMARY KEY IDENTITY(1,1),
    OyunID INT,
    OyuncuID INT,
    Puan BIGINT,
    Tarih DATETIME DEFAULT GETDATE(),
    --referanslar
    FOREIGN KEY (OyunID) REFERENCES Oyunlar(OyunID),
    FOREIGN KEY (OyuncuID) REFERENCES Oyuncular(OyuncuID)
);



----------------------------------------------------------------------
--INSERT ÝÞLEMLERÝ
----------------------------------------------------------------------



INSERT INTO Kategoriler(KategoriAdi, ZorlukSeviyesi) VALUES 
('Atari', 3), 
('Dövüþ', 5), 
('Platform', 2), 
('Spor', 3), 
('Yarýþ', 4);

INSERT INTO Oyuncular (TakmaAd, ToplamJeton) VALUES 
('kolaa', 1000), ('combischel', 1000), ('wellmouch', 40), 
('hazbro43', 200), ('DNLSoftware', 125), ('blyks', 65),
('kovalentt', 300), ('psycho', 650), ('lorded', 100),
('serenoid', 10), ('vecous', 455),('rattle', 305), ('ssenvy', 85), 
('bonsel', 755), ('rainlox', 5),('rulinggame', 195), ('muratabigf', 205),
('sosisteyze', 1000);

INSERT INTO Oyunlar VALUES 
('Pac-Man', 1, 1980), 
('Street Fighter II', 2, 1991), 
('Super Mario Bros', 3, 1985),
('Mortal Kombat', 2, 1992), 
('Tetris', 1, 1984), 
('Donkey Kong', 3, 1981),
('OutRun', 5, 1986), 
('FIFA 94', 4, 1993), 
('Metal Slug', 1, 1996);

INSERT INTO Skorlar (OyunID, OyuncuID, Puan) VALUES 
(1, 1, 28450), (1, 2, 19200), (1, 7, 36100), (1, 12, 42000), (1, 15, 15600),
(2, 2, 10800), (2, 4, 12500), (2, 8, 9100), (2, 11, 14200), (2, 18, 11300),
(3, 1, 16200), (3, 3, 15800), (3, 5, 13400), (3, 10, 21000), (3, 14, 18900),
(4, 3, 45600), (4, 6, 32100), (4, 10, 58900), (4, 13, 27500), (4, 17, 12000), (4, 18, 51000),
(5, 7, 105400), (5, 9, 88200), (5, 13, 120500), (5, 16, 95000), (5, 17, 77000),
(7, 8, 5200), (7, 4, 7100), (7, 18, 8900), (7, 6, 6400), (7, 12, 5800),
(8, 5, 8400),(8, 9, 11200), (8, 12, 15600), (8, 15, 7800), (8, 16, 13400), (8, 1, 9900),
(9, 1, 4100), (9, 2, 3850), (9, 4, 6200), (9, 11, 7500), (9, 14, 5300);



----------------------------------------------------------------------
--JOIN SORGUSU / Hangi oyuncu, hangi kategorideki oyundan ne kadar puan aldý?
----------------------------------------------------------------------



SELECT O.TakmaAd, G.OyunAdi, K.KategoriAdi, S.Puan 
FROM Skorlar S
--join þartlarý
JOIN Oyuncular O ON S.OyuncuID = O.OyuncuID
JOIN Oyunlar G ON S.OyunID = G.OyunID
JOIN Kategoriler K ON G.KategoriID = K.KategoriID
--sýralý listeleme
ORDER BY S.Puan DESC;



----------------------------------------------------------------------
--STORED PROCEDURE OLUÞTURMA / 3 TANE
----------------------------------------------------------------------
GO



--Soru 1: Oyuncunun jeton sayýsýný güncelleyen bir Stored Procedure oluþturun.
CREATE PROC sp_JetonGuncelle @ID INT, @YeniMiktar INT 
AS 
BEGIN 
    UPDATE Oyuncular 
    SET ToplamJeton = @YeniMiktar -- yeni miktara eþitle
    WHERE OyuncuID = @ID 
END;

--Çaðýrma: 
EXEC sp_JetonGuncelle @ID=1, @YeniMiktar=200;
GO



--Soru 2: Belirli bir puanýn altýndaki skorlarý sistemden temizleyen bir Stored Procedure oluþturun.
CREATE PROC sp_DusukSkorlariTemizle @MinPuan BIGINT
AS
BEGIN
    DELETE FROM Skorlar WHERE Puan < @MinPuan
END;

-- Çaðýrma:
EXEC sp_DusukSkorlariTemizle 4000;
GO



--Soru3 : Yeni bir skor giriþi yapan Stored Procedure oluþturun.
CREATE PROC sp_SkorEkle @OyunID INT, @OyuncuID INT, @Puan BIGINT 
AS 
BEGIN 
    INSERT INTO Skorlar(OyunID, OyuncuID, Puan) 
    VALUES (@OyunID, @OyuncuID, @Puan) 
END;

--Çaðýrma: 
EXEC sp_SkorEkle @OyunID=1, @OyuncuID=4, @Puan=50000; -- okunulabilirlik için deðiþkenler belirtildi.
GO



----------------------------------------------------------------------
--VIEW OLUÞTURMA / 3 TANE
----------------------------------------------------------------------



--Soru 1: Her oyuncunun toplam oynadýðý oyun sayýsýný gösteren bir View oluþturun.
CREATE VIEW view_OyuncuIstatistik AS 
SELECT 
    TakmaAd, 
    (SELECT COUNT(*) FROM Skorlar 
      WHERE Skorlar.OyuncuID = Oyuncular.OyuncuID) -- oyuncuya ait skorlardan buluyoruz.
        AS ToplamOyunSayisi 
FROM Oyuncular;
GO

--Çaðýrma:
SELECT * FROM view_OyuncuIstatistik;
GO



--Soru 2: Zor (Zorluk > 3) kategorisindeki oyunlarý listeleyen View.
CREATE VIEW view_ZorOyunlar AS 
SELECT O.OyunAdi, K.KategoriAdi 
FROM Oyunlar O 
JOIN Kategoriler K ON O.KategoriID = K.KategoriID 
WHERE K.ZorlukSeviyesi > 3;
GO

--Çaðýrma:
SELECT * FROM view_ZorOyunlar;
GO



--Soru 3: En son atýlan 5 skoru detaylarýyla gösteren View.
CREATE VIEW view_SonBesSkor AS 
SELECT TOP 5 O.TakmaAd, G.OyunAdi, S.Puan, S.Tarih 
FROM Skorlar S 
--join þartlarý
JOIN Oyuncular O ON S.OyuncuID = O.OyuncuID 
JOIN Oyunlar G ON S.OyunID = G.OyunID 
ORDER BY S.Tarih DESC;
GO

--Çaðýrma:
SELECT * FROM view_SonBesSkor;
GO



----------------------------------------------------------------------
--TRIGGER OLUÞTURMA / 3 TANE
----------------------------------------------------------------------



--Soru 1: Yeni bir oyuncu eklendiðinde ona Hoþ geldin bonusu otomatik 25 jeton veren trigger.
CREATE TRIGGER trg_HosgeldinJetonu 
ON Oyuncular 
AFTER INSERT 
AS 
BEGIN 
    UPDATE Oyuncular 
    SET ToplamJeton = ToplamJeton + 25 
    WHERE OyuncuID IN (SELECT OyuncuID FROM inserted) --sadece yeni eklenen oyunculara iþlem yap.
END;

--Kullaným Örneði:
INSERT INTO Oyuncular (TakmaAd) VALUES ('YeniGamer2026');
SELECT TakmaAd, ToplamJeton FROM Oyuncular 
WHERE TakmaAd = 'YeniGamer2026';
GO



--Soru 2: Skor tablosundan bir kayýt silindiðinde, oyuncuya 3 jeton hediye eden trigger.
CREATE TRIGGER trg_JetonIade  
ON Skorlar 
AFTER DELETE 
AS 
BEGIN 
    UPDATE Oyuncular 
    SET ToplamJeton = ToplamJeton + 3
    FROM Oyuncular O 
    JOIN deleted D ON O.OyuncuID = D.OyuncuID -- silinen oyuncu id bul ve ekle.
END;

--Kullaným Örneði:
SELECT TakmaAd, ToplamJeton FROM Oyuncular WHERE OyuncuID = 4;
DELETE TOP (1) FROM Skorlar WHERE OyuncuID = 4;
SELECT TakmaAd, ToplamJeton FROM Oyuncular WHERE OyuncuID = 4;
GO



--Soru 3: 1900'den küçük çýkýþ yýlý girilmesini engelleyen trigger.
CREATE TRIGGER trg_YilKontrol 
ON Oyunlar 
AFTER INSERT,UPDATE -- hem güncelleme hem ekleme durumu için çalýþýr.
AS 
BEGIN 
    IF EXISTS ( -- eðer deðer 1900 den küçkse gir.
        SELECT * FROM inserted 
        WHERE CikisYili < 1900) 
    BEGIN 
        RAISERROR('Hatalý yýl giriþi!', 16, 1) -- hata ver geri gönder.
        ROLLBACK TRANSACTION 
    END 
END;


-- Kullaným Örneði:
INSERT INTO Oyunlar (OyunAdi, KategoriID, CikisYili) 
VALUES ('Antika Oyun', 1, 1850);
GO



----------------------------------------------------------------------
--FUNCTION OLUÞTURMA / 3 TANE
----------------------------------------------------------------------



--Soru 1: Bir oyuna ait en yüksek puaný döndüren fonksiyon.
CREATE FUNCTION fn_EnYuksekSkor(@OyunID INT) 
RETURNS BIGINT 
AS 
BEGIN 
    RETURN (SELECT MAX(Puan) FROM Skorlar WHERE OyunID = @OyunID) -- oyun idsine ait filtrelemeden sonra max puaný bul.
    END;
GO

--Çaðýrma:
SELECT dbo.fn_EnYuksekSkor(1) 
GO



--Soru 2: Bir oyuncunun jeton durumuna göre VIP olup olmadýðýný döndüren fonksiyon.
CREATE FUNCTION fn_VipKontrol(@OyuncuID INT) 
RETURNS NVARCHAR(10) 
AS 
BEGIN 
    DECLARE @j INT = (SELECT ToplamJeton FROM Oyuncular WHERE OyuncuID = @OyuncuID); --oyuncunun jetonunu deðiþkene al.
    RETURN 
        CASE 
            WHEN @j > 700 THEN 'VIP' 
            ELSE 'Normal' 
        END 
END;
GO

--Çaðýrma: 
SELECT dbo.fn_VipKontrol(1)
GO



--Soru 3: Ýki tarih arasýndaki toplam skor sayýsýný veren fonksiyon.
CREATE FUNCTION fn_TarihAraligiSkor(@Bas DATE, @Bit DATE) 
RETURNS INT 
AS 
BEGIN 
    RETURN (SELECT COUNT(*) FROM Skorlar WHERE Tarih BETWEEN @Bas AND @Bit) -- aralýktaki skorlarý filtrele ve sayýsýný gönder.
END;
GO

--Çaðýrma: 
SELECT dbo.fn_TarihAraligiSkor('2025-01-12','2026-01-12')
GO



----------------------------------------------------------------------
--ÝÇ ÝÇE SELECT OLUÞTURMA / 3 TANE
----------------------------------------------------------------------



--Soru 1: En yüksek skoru yapan oyuncunun tüm bilgilerini getirin.
SELECT * FROM Oyuncular 
WHERE OyuncuID = (SELECT TOP 1 OyuncuID FROM Skorlar ORDER BY Puan DESC);



--Soru 2: Hiç skoru olmayan oyuncularýn jetonlarýný  yapýn
UPDATE Oyuncular SET ToplamJeton = 0 
WHERE OyuncuID NOT IN (SELECT DISTINCT OyuncuID FROM Skorlar); -- skor tablosunda kayýtý yoksa jetonu sýfýrla.



--Soru 3: Kategorisindeki zorluk seviyesi, genel ortalama zorluk seviyesinden yüksek olan oyunlarý getirin.
SELECT OyunAdi FROM Oyunlar 
WHERE KategoriID IN (SELECT KategoriID FROM Kategoriler 
WHERE ZorlukSeviyesi > (SELECT AVG(ZorlukSeviyesi) FROM Kategoriler));-- ortalama zorluk seviyesinden büyük olan kategorileri getir.