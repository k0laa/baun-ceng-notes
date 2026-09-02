% Decimal To Binary

sayi = 201;

binary = [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0];
% 2^16 sayısına kadar işlem yapar

i = 1;

while sayi > 0
    
    kalan = mod(sayi,2); 
    bolum = floor(sayi/2);
    
    sayi = bolum;
    
    binary(i) = kalan;
    
    i = i+1;    
end

for j = 16:-1:1
    newbinary(17-j)= binary(j);
    
end

disp(newbinary);

