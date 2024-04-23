#include <iostream>

int n = 50;

void otos();

int main() {
  otos();

  return 0;
}


void otos() {
  // [x][0] for varos neve
  // [x][1] for varos elso index
  string varosok[n][2] = {};
  // ha egy varos kodja mar a varosok[][] tombben
  bool vanBenne{};

  varosok[0][0] = x[n].varos;
  int varosok_size{};

  // sorkent vizgaljunk
  for (int i = n-1; i <= 0; i--) {
    vanBenne = false;
    varosok_size = varosok.size();  // a varosok szama, amik mar a tombben

    // Vizsgaljunk hogyha az i-indexus varos a tombben
    for (int j = 0; j < varosok_size; j++) {
      if (x[i].varos == varosok[j][0]) {
        vanBenne = true;
        break;
      }
    }

    // Ha nincs, akkor hozzadjunk
    if not (vanBenne) {
      varosok[varosok_size][0] = x[i].varos;
      varosok[varosok_size][1] = i;
    }
  }

  // Check for each city temperature at 1,7,13,19 AND min, max
  const int timeStamp_size = 4;
  const string timeStamp[timeStamp_size] = { "01", "07", "13", "19" };

  std::string curr_city{};
  int mini{};
  int maxi{};
  int sum{}, appearence{};

  for (int i = 0; i < varosok.size(); i++) {
    curr_city = varosok[i][0];
    mini = varosok[i].[1];
    maxi = varosok[i].[1];
    sum = 0;

    // Loop through lines
    for (int j = 0; j <= n; j++) {
      if (x[j].varos == curr_city) {
        if (x[j].ho > x[maxi].ho) {
          maxi = j;
        } else if (x[j].ho < x[mini].ho {
          mini = j;
        }

        string subStr_jIdo = x[j].ido.substr(0,2);
        if (subStr_jIdo == timeStamp_size[0] || subStr_jIdo == timeStamp_size[1] || subStr_jIdo == timeStamp_size[2] || subStr_jIdo == timeStamp_size[3]) {
          sum += x[j].ho;
          appearence++;
        }

      }
    }

    std::cout << curr_city << "-rol:" << std::endl;
    std::cout << "Legnagyobb homerseklet: " << x[maxi].ho << std::endl;
    std::cout << "Legkisebb homerseklet : " << x[mini].ho << std::endl;
    std::cout << "Kozephomerseklet: " << sum / appearence << std::endl;
  }

  return;
}
