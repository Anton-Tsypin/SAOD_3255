# Пятое задание

Время жизни объектов в C++?  
глобальные объекты объявляются перед началом работы программы, и уничтожаются после её завершения (функции main),  
локальные объекты объявляются и уничтожаются в пределах одного блока кода (внутри функции, например).

Случаи неявного копирования объектов в C++?  
при отсутствии конструктора копирования, при передачи объекта в функцию, например,  
при отсутствии перегрузки оператора присваивания operator=().  

В каком порядке создаются составные объекты (потомки или агрегаты в C++)?  
сначала создаются вложенные объекты,  
уничтожается всё в обратном порядке.  

Как объявить и использовать шаблон класса?  
с помощью ключевых слов  
template <typename somethig>  
перед объявлением класса,  
далее в теле класса упоминание типа параметризуемого объекта нужно заменять указанным something.  
