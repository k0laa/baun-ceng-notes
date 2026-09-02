%sabit nokta iterasyonu
clear; clc;

x0=0.5;

x(1) = x0;
y(1) = x0;
step=5;

for i=1:step
    x(i+1) = (x(i)-log(exp(x(i))))/2;
    %x(i+1) = 1/(x(1)^2 -1);
    %x(i+1) = (x(i)+1).^(1/3);
    
    e(i) = abs(x(i+1)-x(i));
    
    fprintf("\nx%d = %d",i,x(i));
    fprintf("\nE%d = %d",i,e(i));
    fprintf("\n");

end
