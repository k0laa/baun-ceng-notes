-----------------------------------------------------
--1.Soru : Öncelikle tablolarýn create table ve insert sorgu cümlelerini tasarlayýnýz. 
-----------------------------------------------------

CREATE DATABASE LibraryManagementSystem
GO

USE LibraryManagementSystem

CREATE TABLE Books (
    BookID INT PRIMARY KEY IDENTITY(1,1),
    Title NVARCHAR(50) NOT NULL,
    Author NVARCHAR(50) NOT NULL,
    Genre NVARCHAR(20),
    Stock INT DEFAULT 0 NOT NULL
);

CREATE TABLE Members (
    MemberID INT PRIMARY KEY IDENTITY(1,1),
    FirstName NVARCHAR(30) NOT NULL,
    LastName NVARCHAR(30) NOT NULL,
    JoinDate DATETIME DEFAULT GETDATE()
);  

CREATE TABLE BorrowedBooks (
    BorrowID INT PRIMARY KEY IDENTITY(1,1),
    MemberID INT NOT NULL,
    BookID INT NOT NULL,
    BorrowDate DATETIME DEFAULT GETDATE(),
    ReturnDate DATETIME,
    FOREIGN KEY (MemberID) REFERENCES Members(MemberID),
    FOREIGN KEY (BookID) REFERENCES Books(BookID),
);

INSERT INTO Books (Title, Author, Genre, Stock) VALUES 
('Suç ve Ceza', 'Fyodor Dostoyevski', 'Roman', 5),
('Sineklerin Tanrýsý', 'William Golding', 'Roman', 3),
('Yapay Zeka', 'John McCarthy', 'Teknoloji', 4),
('Veri Bilimi', 'Jake VanderPlas', 'Teknoloji', 2),
('Ýki Þehrin Hikayesi', 'Charles Dickens', 'Tarih', 6);


INSERT INTO Members (FirstName, LastName, JoinDate) VALUES 
('Ali', 'Yýlmaz', '2023-01-12'),
('Ayþe', 'Kaya', '2022-09-20'),
('Mehmet', 'Demir', '2023-06-05'),
('Elif', 'Özcan', '2024-02-15'),
('Kerem', 'Çelik', '2023-11-23');

INSERT INTO BorrowedBooks (MemberID, BookID, BorrowDate, ReturnDate) VALUES 
(1, 2, '2024-04-10', NULL),
(3, 1, '2024-03-25', '2024-04-05'),
(2, 4, '2024-04-01', NULL),
(4, 3, '2024-04-03', NULL),
(5, 5, '2024-02-15', '2024-03-01');



GO
-----------------------------------------------------
--2.Soru : Belirli bir kitabýn stok sayýsýný artýran bir Stored Procedure oluþturun. 
--Kitap ID'si ve artýrýlacak miktarý parametre olarak alsýn. 
-----------------------------------------------------

CREATE PROC sp_StokArttir
    @BookID INT,         
    @ArtisMiktari INT     
AS
BEGIN
    UPDATE Books
    SET Stock = Stock + @ArtisMiktari
    WHERE BookID = @BookID;        
END;


--Örnek Kullaným
SELECT Stock FROM Books WHERE BookID = 3
EXEC sp_StokArttir @BookID = 3, @ArtisMiktari = 5;
SELECT Stock FROM Books WHERE BookID = 3



GO
-----------------------------------------------------
--3.Soru : Ödünç alýnan kitaplarý listeleyen bir Stored Procedure oluþturun. 
--Parametre olarak üyenin ID'si verildiðinde sadece o üyenin ödünç aldýðý kitaplarý göstersin. 
-----------------------------------------------------

CREATE PROC sp_UyeOduncKitaplari
    @MemberID INT
AS
BEGIN
    SELECT
        CONCAT(m.FirstName,' ', m.LastName) AS 'Adý Soyadý',
        b.Title AS 'Ödünç Alýnan Kitap',
        bb.BorrowDate AS 'Ödünç Alma Tarihi',
        bb.ReturnDate AS 'Geri Verme Tarihi'
    FROM BorrowedBooks bb
    JOIN Members m ON bb.MemberID = m.MemberID
    JOIN Books b On bb.BookID = b.BookID
    WHERE bb.MemberID = @MemberID
END


--Örnek Kullaným
EXEC sp_UyeOduncKitaplari @MemberID = 2;



GO
-----------------------------------------------------
--4.Soru : Ödünç alýnmýþ ancak henüz iade edilmemiþ kitaplarý listeleyen bir View oluþturun.
-----------------------------------------------------

CREATE VIEW view_IadeEdilmemisKitaplar AS 
SELECT 
    CONCAT(m.FirstName,' ', m.LastName) AS 'Adý Soyadý',
    b.Title AS 'Kitap Ýsmi',
    bb.BorrowDate AS 'Ödünç Alýnma Tarihi' 
FROM BorrowedBooks bb
JOIN Books b ON bb.BookID = b.BookID
JOIN Members m ON bb.MemberID = m.MemberID
WHERE bb.ReturnDate IS NULL;
GO


--Örnek Kullaným
SELECT * FROM view_IadeEdilmemisKitaplar;



GO
-----------------------------------------------------
--5.Soru : Tüm üyelerin ödünç aldýðý kitap sayýsýný gösteren bir View oluþturun. 
-----------------------------------------------------

CREATE VIEW view_UyeKitapSayilari AS 
SELECT 
    CONCAT(m.FirstName,' ', m.LastName) AS 'Adý Soyadý',
    COUNT(bb.BorrowID) AS 'Toplam Ödünç Alýnan Kitap Sayýsý'
FROM BorrowedBooks bb
JOIN Members m ON bb.MemberID = m.MemberID
GROUP BY M.MemberID, M.FirstName, M.LastName;
GO


--Örnek Kullaným
SELECT * FROM View_UyeKitapSayilari;



GO
-----------------------------------------------------
--6.Soru : Bir kitap ödünç alýndýðýnda stoktan 1 eksiltmek için bir Trigger oluþturun. 
-----------------------------------------------------

CREATE TRIGGER trg_KitapStokAzalt 
ON BorrowedBooks 
AFTER INSERT 
AS 
BEGIN 
    UPDATE Books 
    SET Stock = Stock - 1 
    FROM Books B 
    INNER JOIN inserted I ON B.BookID = I.BookID; 
END;


--Örnek Kullaným
SELECT * FROM Books WHERE BookID = 3;
INSERT INTO BorrowedBooks (MemberID, BookID, BorrowDate, ReturnDate) 
VALUES (1, 3, '2024-04-25', NULL); 
SELECT * FROM Books WHERE BookID = 3;



GO
-----------------------------------------------------
--7.Soru : Bir ödünç kaydý silindiðinde stok miktarýný 1 artýran bir Trigger oluþturun. 
-----------------------------------------------------

CREATE TRIGGER trg_KitapStokArttir
ON BorrowedBooks 
AFTER DELETE 
AS 
BEGIN 
    UPDATE Books 
    SET Stock = Stock + 1 
    FROM Books B 
    JOIN deleted d ON B.BookID = d.BookID; 
END;



GO
-----------------------------------------------------
--8.Soru : Kitap ödünç alýnýrken Stock = 0 olan kitaplarýn ödünç alýnmasý engelleyen Triggerý oluþturun. 
-----------------------------------------------------

CREATE TRIGGER trg_StokKontrolEt
ON BorrowedBooks
INSTEAD OF INSERT
AS
BEGIN
    -- Eðer eklenecek kitabýn stoðu 0'dan büyükse iþlemi yap
    IF EXISTS (
        SELECT 1 FROM Books B
        JOIN inserted I ON B.BookID = I.BookID
        WHERE B.Stock > 0
    )
    BEGIN
        -- Kaydý ekle
        INSERT INTO BorrowedBooks (BorrowID, MemberID, BookID, BorrowDate, ReturnDate)
        SELECT BorrowID, MemberID, BookID, BorrowDate, ReturnDate FROM inserted;

        -- Stoðu 1 azaltan trigger var zaten
    END
    ELSE
    BEGIN
        -- Stok 0 ise iþlemi iptal et ve hata mesajý fýrlat
        RAISERROR('HATA: Bu kitabýn stoðu yok.', 16, 1);
        ROLLBACK TRANSACTION;
    END
END;



GO
-----------------------------------------------------
--9.Soru : Bir üyenin ödünç aldýðý toplam kitap sayýsýný döndüren bir Function oluþturun.  
-----------------------------------------------------

CREATE FUNCTION fn_UyeKitapSayisi(@MemberID INT)
RETURNS INT
AS
BEGIN
    DECLARE @ToplamSayi INT;

    SELECT @ToplamSayi = COUNT(*) 
    FROM BorrowedBooks 
    WHERE MemberID = @MemberID;

    RETURN @ToplamSayi;
END;
GO


--Örnek Kullaným
SELECT dbo.fn_UyeKitapSayisi(1) AS 'Toplam Kitap';



GO
-----------------------------------------------------
--10.Soru : Stokta olan toplam kitap sayýsýný hesaplayan bir Function oluþturun. 
-----------------------------------------------------

CREATE FUNCTION fn_ToplamKitapStogu()
RETURNS INT
AS
BEGIN
    DECLARE @ToplamStok INT;

    SELECT @ToplamStok = SUM(Stock)
    FROM Books

    RETURN @ToplamStok;
END;
GO


--Örnek Kullaným
SELECT dbo.fn_ToplamKitapStogu() AS 'Toplam Kitap Sayýsý';



GO
-----------------------------------------------------
--11.Soru : En fazla ödünç kitap alan üyelerin adýný ve soyadýný listeleyen iç içe select sorgusunu oluþturun. 
-----------------------------------------------------

SELECT 
    M.FirstName, 
    M.LastName
FROM Members M
WHERE M.MemberID IN (
    SELECT BB.MemberID
    FROM BorrowedBooks BB
    GROUP BY BB.MemberID
    HAVING COUNT(BB.BorrowID) = (
        SELECT MAX(KitapSayisi)
        FROM (
            SELECT COUNT(BorrowID) AS KitapSayisi
            FROM BorrowedBooks
            GROUP BY MemberID
        ) AS AltTablo
    )
);



GO
-----------------------------------------------------
--12.Soru : Stok sayýsý ortalama stoktan az olan kitaplarý listeleyen iç içe select sorgusunu oluþturun.
-----------------------------------------------------


SELECT 
    Title, 
    Author, 
    Stock
FROM Books
WHERE Stock < (
    SELECT AVG(Stock) 
    FROM Books
);