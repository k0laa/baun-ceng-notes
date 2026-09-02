function root = newtonRaphson(func, derivative, initial_guess, tolerance, max_iterations)
    % func: İncelenen fonksiyonu temsil eden bir işlev.
    % derivative: Fonksiyonun türevidir.
    % initial_guess: Başlangıç tahmini.
    % tolerance: Kabul edilebilir hata düzeyi.
    % max_iterations: Maksimum iterasyon sayısı.
    
    % func = @(x) x^2 - 4;
    % derivative = @(x) 2 * x;
    % initial_guess = 1.5;
    % tolerance = 1e-6;
    % max_iterations = 100;
    
    x = initial_guess;
    iteration = 0;
    
    while true
        % Fonksiyonun değerini ve türevidirini hesapla
        f = func(x);
        df = derivative(x);
        
        % Newton-Raphson iterasyon formülünü uygula
        x_new = x - f / df;
        
        % Yeni tahminin hata düzeyine göre kontrol et
        if abs(x_new - x) < tolerance
            root = x_new;
            break;
        end
        
        x = x_new;
        iteration = iteration + 1;
        
        % Maksimum iterasyon sayısını aşma kontrolü
        if iteration >= max_iterations
            error('Yeterli yakınsama sağlanamadı. Maksimum iterasyon sayısına ulaşıldı.');
        end
    end
end


