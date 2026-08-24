use SirketDB

-- 1. soru ---------------------------------------------
select concat(Ad,' ', Soyad) as [Personel Adý ve Soyadý]
from Personel;


--2. soru ---------------------------------------------
select lower(proje_ad) 
from proje;


--3. soru ---------------------------------------------
select distinct maas
from personel


--4. soru ---------------------------------------------
select *
from personel
where year(baslama_tarihi) = 2002 and month(baslama_tarihi) = 5;


--5. soru ---------------------------------------------
select birim_no, count(*) as KacKisiCalisiyor
from Personel
group by birim_no
order by KacKisiCalisiyor desc;


--6. soru ---------------------------------------------
select personel.ad, personel.soyad, count(cocuk.personel_no) as KacCocuguVar
from personel, cocuk
where personel.personel_no = cocuk.personel_no
group by personel.ad, personel.soyad
having count(cocuk.personel_no) > 1;


--7. soru ---------------------------------------------
select birim.birim_ad, count(personel.birim_no) as [Toplam Calýsan Sayýsý]
from personel, birim
where birim.birim_no = personel.birim_no
group by birim.birim_ad
having count(personel.birim_no) < 5;


--8. soru ---------------------------------------------
select  ilce.ilce_ad, il.il_ad, count(personel.personel_no) as [Toplam Calýsan Sayýsý]
from personel, ilce, il 
where personel.dogum_yeri = ilce.ilce_no and ilce.il_no = il.il_no
group by ilce.ilce_ad, il.il_ad
having count(personel.personel_no) > 3;


--9. soru ---------------------------------------------
select 
    p.ad,
    p.soyad,
    u.unvan_ad,
    pr.proje_ad,
    pr.baslama_tarihi,
    pr.planlanan_bitis_tarihi,
    b.birim_ad
into PersonelProjeListesi
from personel p, proje pr, unvan u, birim b, gorevlendirme g
where g.personel_no = p.personel_no and 
      g.proje_no = pr.proje_no and 
      p.unvan_no = u.unvan_no and 
      b.birim_no = p.birim_no

SELECT * FROM PersonelProjeListesi;
