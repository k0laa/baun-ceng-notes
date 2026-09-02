function [x, iteration] = jacobi(A, b, x0, tolerance, max_iterations)
    

    % Matris boyutunu kontrol et
    [m, n] = size(A);
    if m ~= n
        error('Girilen matris kare matris olmalıdır.');
    end
    
    % Başlangıç tahminini kontrol et
    if length(x0) ~= n
        error('Başlangıç tahmini matrisin boyutuyla uyumlu olmalıdır.');
    end
    
    % İterasyon sayacını başlat
    iteration = 0;
    
    % Başlangıç tahminini güncelle
    x = x0;
    
    % İteratif Jacobi yöntemi
    while true
        x_new = zeros(n, 1);
        
        for i = 1:n
            sigma = A(i, 1:n) * x - A(i, i) * x(i);
            x_new(i) = (b(i) - sigma) / A(i, i);
        end
        
        % Toleransı kontrol et
        if norm(x_new - x, inf) <= tolerance
            break;
        end
        
        % Maksimum iterasyon sayısını kontrol et
        iteration = iteration + 1;
        if iteration >= max_iterations
            warning('Maksimum iterasyon sayısına ulaşıldı. Yakınsama sağlanamadı.');
            break;
        end
        
        % x'i güncelle
        x = x_new;
    end
end
