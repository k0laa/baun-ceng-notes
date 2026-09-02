x(1) = 0.5;

step= 10 %input("N-R yontemi icin adim sayisini giriniz:");

for i=1:step

	x(i+1) = x(i)-f(x(i))/df(x(i));
    hata = abs(x(i+1)-x(i));
    
end

fprintf("%d adimla yaklaþik kök %f dir \n",step,x(end));