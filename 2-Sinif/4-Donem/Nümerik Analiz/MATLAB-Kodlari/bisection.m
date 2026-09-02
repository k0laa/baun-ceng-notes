%İkiye Bölme
clear; clc;
format short

f = @(x) x - tan(x);

a0=str2double(input('1. sayi', 's'));
b0=str2double(input('2. sayi', 's'));
hata = 0.07;

fprintf("\nf(a0) = %d",f(a0));
fprintf("\nf(b0) = %d",f(b0));
fprintf("\n");

a(1) = a0;
b(1) = b0;
step = 100;

for i=1:step
        
    x(i) = (a(i)+b(i))/2;
    
    if f(x(i))*f(b(i))<0
        a(i+1) = x(i);
        b(i+1) = b(i);
        
    elseif f(a(i))*f(x(i))<0
        a(i+1) = a(i);
        b(i+1) = x(i);
        
    else
        disp("f bolzano teoremine uymuyor kontrol edin")
        break;
    end
    
    fprintf("\na%d = %d",i-1,a(i));
    fprintf("\nb%d = %d",i-1,b(i));
    fprintf("\nx%d = %d",i-1,x(i));
    fprintf("\nf(x%d) = %d",i-1,f(x(i)));
    fprintf("\n");

     e(i) = abs(b0-a0)/2^i;
     if(e(i)<hata)
         break
     end

end


