x = 1;
y = 1;

for z = 0:10
    toplam = x+y;
    x = y;
    y = toplam;
    
    disp(toplam)
end
