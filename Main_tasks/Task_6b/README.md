# Задание 6b. Вариант 7

# Алгоритм Рабина-Карпа.

Алгоритм Рабина-Карпа использует полиноминальные хеши для первичной проверки соответствия строк.  
Определяется хеш образца, далее в тексте определяются хеши подстрок, сравниваются с хешом образца.  
При совпадении значений хешей, строки проверяются посимвольно.  
Алгоритм хорошо работает, когда есть несколько разных хешей, по которым нужно провести поиск в большом тексте.  

У меня получилось написать данный алгоритм на C++.  
Плюсы: работает эффективно и без ошибок.  
Минусы: потратил на это всю ночь вместо сна.  
