/*
 * Alexander Kazakov <alexander.d.kazakov@gmail.com>
 *
 * Code is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 */

#include<iostream>
#include<cmath>

using namespace std;

double round(double number);
void margin(int size);
void plot_upper(int size, int* values, string line, string graph, string axis);
void plot_center(int size, int* values, string line, string axis);
void plot_lower(int size, int* values, string line, string graph, string axis);

