f = @(x) (x^2)/2 - sin(x);

x(1) = 1.5;
x(2) = 2;

hata = 0.05;
step = 100;

fprintf("\nx0 = %f",x(1));
fprintf("\nx1 = %f",x(2));
fprintf("\n");

i = 2;
while abs(x(i)-x(i-1))>hata
    
    i = i+1;
    
    x(i) = x(i-1)- f(x(i-1))*((x(i-1)-x(i-2))/(f(x(i-1))- f(x(i-2))));
    fprintf("\nx%i = %f",i-1,x(i));
    fprintf("\ne%i = %f",i-2,abs(x(i)-x(i-1)));

    fprintf("\n");

end

