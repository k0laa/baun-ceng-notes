clc

hata = input('Hatayi giriniz: ');
 
a0 = 1;
b0 = 2;

i = 1;
step = 0;
while(abs(b0-a0)/2^i > hata)
    abs(b0-a0)/2^i;
    i = i+1;
    step = step+1;
end
 
fprintf('%d adim gidilmesi gerekir', step);