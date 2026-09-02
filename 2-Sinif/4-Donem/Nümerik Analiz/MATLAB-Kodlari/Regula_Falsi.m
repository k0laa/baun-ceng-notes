clear; clc;

a0=3;
b0=4;

fprintf("\nf(a0) = %d",f(a0));
fprintf("\nf(b0) = %d",f(b0));
fprintf("\n");
hata = 0.0001;

a(1) = a0;
b(1) = b0;
i = 1;
while(true) 
    
    x(i) = (a(i)*f(b(i))-b(i)*f(a(i)))/(f(b(i))-f(a(i)));
    
    if f(x(i))*f(b(i))<0
        a(i+1) = x(i);
        b(i+1) = b(i);
        
    elseif f(a(i))*f(x(i))<0
        a(i+1) = a(i);
        b(i+1) = x(i);
    else
        disp("fonksiyon bolzano teoremine uymuyor kontrol edin")
        break;
    end
    
    fprintf("\na%d = %d",i-1,a(i));
    fprintf("\nb%d = %d",i-1,b(i));
    fprintf("\nx%d = %d",i-1,x(i));
    fprintf("\nf(x%d) = %d",i-1,f(x(i)));
    fprintf("\n");
 
    e(1) = abs(x(i)-b0);
    
    if(i>1)
    
        e(i+1) = abs(x(i)-x(i-1));
        if(e(i)<hata)
            break;
        end
    end
 
    i=i+1;
end




