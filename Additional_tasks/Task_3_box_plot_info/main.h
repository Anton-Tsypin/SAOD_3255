#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <numeric>
#include <cmath>

std::tuple<double, double, double> Box_info(std::vector<double> vector, int numbers) {

  // Настройки
	std::cout.precision(numbers);
  std::cout << std::scientific;
	sort(vector.begin(), vector.end());
  size_t size = vector.size();
  
  // Среднее
  double mean = std::accumulate(vector.begin(), vector.end(), 0.0) / size;

	// Дисперсия
  double D;
  for(size_t i = 0; i < size; i++){
    D += pow(vector[i] - mean, 2);
  }
  D /= (size - 1);

	// Стандартное отклонение
	double stddev = pow(D, 0.5);

  // Медиана
	double median;
	if (size % 2 != 0) {
		median = vector[size / 2];
  }
	else {
    median = (vector[size / 2] + vector[size / 2 - 1]) / 2;
  }

  // Нижний (первый) квартиль
	double lq;
	if (size % 4 != 0) {
		lq = vector[size / 4];
  }
	else {
    lq = (vector[size / 4] + vector[size / 4 - 1]) / 2;
  }
  
  // Верхний (третий) квартиль
  double uq;
	if (size % 4 != 0) {
		uq = vector[size / (4. / 3.)];
  }
  else {
    uq = (vector[size / (4. / 3.)] + vector[size / (4. / 3.) - 1]) / 2;
  }
  
	// Межквартильный диапазон (между первым и третьим квартилем)
	double mq = uq - lq;

	//Верхняя и нижняя границы
	double min = lq - mq * 1.5;
	double max = uq + mq * 1.5;

  // Вывод
	std::cout << "min\t"    << min    << std::endl;
	std::cout << "lq\t"     << lq     << std::endl;
	std::cout << "median\t" << median << std::endl;
	std::cout << "mean\t"   << mean   << std::endl;
	std::cout << "stddev\t" << stddev << std::endl;
	std::cout << "uq\t"     << uq     << std::endl;
	std::cout << "max\t"    << max    << std::endl;
	std::cout << "out\t"; 
  
  // Выбросы
  std::for_each(vector.cbegin(), vector.cend(),
   [&min, &max](double x) {
      if ((x > max) || (x < min)) {
        std::cout << x << " ";
      }
    }
  );
  
  std::cout << std::endl;

  std::tuple<double, double, double> answer(mean, median, stddev);

  return answer;
}
