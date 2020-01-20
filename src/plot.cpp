/*
 * Alexander Kazakov <alexander.d.kazakov@gmail.com>
 *
 * Code is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 */

#include"plot.h"

double round(double number) {
  return number < 0.0 ? ceil(number - 0.5) : floor(number + 0.5);
}

void margin(int size) {
  for (int i = 0; i < size+size+1; ++i) {cout << endl;}
}

void plot_upper(int size, int* values, string line, string graph, string axis) {
  for (int i = 0; i < size; ++i) {
      for (int b = 0; b < size; ++b) {
          if (size - i == values[b]) cout << line;
          else cout << graph;
    }
    
    if (size-i == values[size]) cout << line;
    else cout << axis;
    
    for (int b = 0; b < size; ++b) {
        if (size-i == values[b+size+1]) cout << line;
        else cout << graph;
    }
    cout << endl;
  }
}

void plot_center(int size, int* values, string line, string axis) {
    for (int i = 0;i < size*2+1; ++i) {
        if (0 == values[i] ) cout << line;
        else cout << axis; 
    }
}

void plot_lower(int size, int* values, string line, string graph, string axis) {
    for (int i = 0;i < size;++i) {
        for (int b = 0; b < size;++b) {
            if (0-i-1 == values[b]) cout << line;
            else cout << graph;}
        
        if (0 -i-1 == values[size]) cout << line;
        else cout << axis;
        
        for (int b = 0; b < size;++b) {
            if (0-i-1 == values[b+size+1]) cout << line;
            else cout << graph;
        } 
        cout << endl;
    }
}
