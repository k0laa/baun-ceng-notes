function root = sekant(func, x0, x1, tolerance, max_iterations)
    % func: İncelenen fonksiyonu temsil eden bir işlev.
    % x0, x1: Başlangıç tahminleri.
    % tolerance: Kabul edilebilir hata düzeyi.
    % max_iterations: Maksimum iterasyon sayısı.
    
    iteration = 0;
    
    while true
        % İki başlangıç değerinden doğru yaklaşımını hesapla
        f0 = func(x0);
        f1 = func(x1);
        slope = (f1 - f0) / (x1 - x0);
        intercept = f1 - slope * x1;
        
        % Doğru ve fonksiyonun kesiştiği noktanın x koordinatını hesapla
        x2 = -intercept / slope;
        
        % Yeni tahminin hata düzeyine göre kontrol et
        if abs(x2 - x1) < tolerance
            root = x2;
            break;
        end
        
        x0 = x1;
        x1 = x2;
        iteration = iteration + 1;
        
        % Maksimum iterasyon sayısını aşma kontrolü
        if iteration >= max_iterations
            error('Yeterli yakınsama sağlanamadı. Maksimum iterasyon sayısına ulaşıldı.');
        end
    end
end
