function x = gaussSeidel(A, b, tolerance, start)

n = length(b);

x = start;

% hata toleransının karesini hesapla
tolerans = tolerance^2;

% Gauss-Seidel iterasyonu
for y = 1:20
    % yeni bir x tahmini hesapla
    for i = 1:n
        sigma = 0;
        for j = 1:i-1
            sigma = sigma + A(i,j)*x(j);
        end
        for j = i+1:n
            sigma = sigma + A(i,j)*x(j);
        end
        x(i) = (b(i) - sigma) / A(i,i);
    end
    
    % hata toleransını kontrol et
    karehata = norm(A*x-b)^2;
    if (karehata < tolerans)
        break;
    end
end