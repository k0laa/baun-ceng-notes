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
