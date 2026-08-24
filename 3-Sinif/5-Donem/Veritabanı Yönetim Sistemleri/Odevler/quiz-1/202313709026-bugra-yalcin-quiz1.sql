--soru 1
create database quiz1
use quiz1

create table personel(
id int,
ad varchar(56) not null,
soyad varchar(56),
yas int,
cinsiyet char,
sehir varchar(56),
ulke varchar(56),
maas float,
);

INSERT INTO Personel (id, ad, soyad, yas, cinsiyet, sehir, ulke, maas)
VALUES
(2, 'Ahmet',  'Yýlmaz',   20, 'E', 'Ankara',   'Turkiye', 2000.00),
(3, 'Mehmet', 'Efe',      22, 'E', 'Bolu',     'Turkiye', 2000.00),
(4, 'Ayse',   'Can',      23, 'B', 'Ýstanbul', 'Turkiye', NULL),
(5, 'Fatma',  'Ak',    35, 'B', 'Ankara',   'Turkiye', 3200.00),
(6, 'John',   'Smith',    45, 'E', 'New York', 'USA',     3000.00),
(7, 'Ellen',  'Smith',    40, 'B', 'New York', 'USA',     3500.00),
(8, 'Hans',   'Müler',  30, 'E', 'Bedin',    'Almanya',  4000.00),
(9, 'Frank',  'Casanne',    35, 'E', 'Paris',    'Fransa',  NULL),
(10, 'Abbas',  'Demir',    26, 'B', 'Adana',    'Turkiye', 2000.00),
(11,'Hatice', 'Topcu',    26, 'B', 'Hatay',    'Turkiye', 2200.00),
(12,'Gulsum', 'Demir',  35, 'E', 'Adana',    'Turkiye', 2000.00);

-- soru 2
update personel set maas = maas*1.1  where ulke = 'Turkiye';

--soru 3
select * from personel where cinsiyet = 'E'

-- soru 4
select ad, soyad, concat(ad,soyad,'@hotmail.com')
from personel

--soru 5
select *
from personel
where maas>2000 and maas<3500

--soru 6
select *
from personel
where maas=2000 or maas=3000 or maas = 4000

--soru 7
select *
from personel
where maas is null

--soru 8
select *
from personel
where ad like 'A%'

-- soru 9
select ad, soyad, ulke, maas, yas
from personel
order by  yas asc

--soru 10
select lower(ad), upper(soyad), maas
from personel

--soru 11
select COUNT(*) as Sayý, AVG(yas) as Yas_Ortalamasi
from personel

--soru 12
update personel set maas = 2500 where maas is null

--soru 13
select min(maas), max(maas)
from personel

--soru 14
select COUNT(*) as Toplam_Kayýt_Sayýsý
from personel

--soru 15
select sum(maas) as Toplam_Odenen_Maas
from personel

--soru 16
select count(*) as Calisan_Sayýsý , ulke
from personel 
group by ulke

--soru 17
select count(*) as Calisan_Sayýsý , ulke
from personel 
where yas>30
group by ulke

--soru 18
select cinsiyet, avg(yas) as Ortalama_Yas, count(*) as Kisi_Sayýsý
from personel
group by cinsiyet

--soru 19
select ulke, avg(maas) as Maas_Ortalamasý, cinsiyet, count(*) as Calisan_Sayýsý
from personel
group by ulke, cinsiyet
order by ulke

--soru 20
select ulke, avg(maas) as Ortalama
from personel
where cinsiyet = 'E'
group by ulke
having count(*) < 2