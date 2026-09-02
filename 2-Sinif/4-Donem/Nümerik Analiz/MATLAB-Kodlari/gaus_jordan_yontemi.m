function gj_ters_matris = gaus_jordan_yontemi(matrix)
    % Kare matris girilmeli
    [m, n] = size(matrix);
    if m ~= n
        error('Girilen matris kare matris olmalıdır.');
    end
    
    % Genişletilmiş matris oluşturma
    genisletilmis_matris = [matrix, eye(n)];
    
    % Gauss-Jordan eleme 
    for k = 1:n
        pivot = genisletilmis_matris(k, k);
        if pivot == 0
            error('Matrisin tersi bulunamıyor.');
        end
        
%         Yukaridaki ifade şöylede olabilirdi 
%         if det(A) == 0
%             error('Matrisin determinantı 0 olduğu için tersi bulunamaz.');
%         end
        
        genisletilmis_matris(k, :) = genisletilmis_matris(k, :) / pivot;
        
        for i = 1:n
            if i ~= k
                factor = genisletilmis_matris(i, k);
                genisletilmis_matris(i, :) = genisletilmis_matris(i, :) - factor * genisletilmis_matris(k, :);
            end
        end
    end
    
    % Ters matrisi ayırma işlemi
    gj_ters_matris = genisletilmis_matris(:, n+1:end);
end
