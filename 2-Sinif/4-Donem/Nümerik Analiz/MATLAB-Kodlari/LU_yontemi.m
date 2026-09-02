function ters_matris_lu = LU_yontemi(matrix)
    % Matris boyutunu kontrol et
    [m, n] = size(matrix);
    if m ~= n
        error('Girilen matris kare matris olmalıdır.');
    end
    
    % alt ve üst üçgensel matrisi elde etmek için matlabın lu fonksiyonunu
    % çağırıyoruz
    [L, U] = lu(matrix);
    
    % Ters matrisi hesapla
    ters_matris_lu = zeros(n);
    for i = 1:n
        b = zeros(n, 1);
        b(i) = 1;
        
        % Ly = b
        y = L\b;
        
        % Ux = y
        x = U\y;
        
        ters_matris_lu(:, i) = x;
    end
end