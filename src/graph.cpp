/*
 * Alexander Kazakov <alexander.d.kazakov@gmail.com>
 *
 * Code is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 */


#include "plot.h"
#include "parser/fparser.hh"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>

static string axis = "+ ";
static string line = "X ";
static string graph = ". ";
static string title = "";
static string y_label = "";
static string x_label = "";

void make_values(int size, double step, int* values, const string &function) {
    FunctionParser fp;
    fp.Parse(function, "x");
    for (int i=0; i< size+size+1; ++i) {
        double x_tic = (i - (size))*step;
        values[i] = int(round( fp.Eval(&x_tic)/step ));
    }
}

void read_file(int size, double xstep, double ystep, int* values, const string &filename) {
    string line;
    ifstream myfile (filename);
    
    if (myfile.is_open()) {
        while (getline (myfile,line)) {
            std::istringstream iss(line);
            double x, y;
            if (!(iss >> x >> y)) { break; } // error
            values[size + int(round(x/xstep))] = int(round(y/ystep));
            cout << int(round(x/xstep)) << " " << int(round(y/ystep)) <<  '\n';
        }
        cout << "Values: " << *values << endl;
        myfile.close();
    }
    else cout << "Unable to open file";
}


void usage() {
        cout << "[Terminal plotter] version: 0.01" << endl;
        cout << "Usage: graph <size> <step> <function(x)>" << endl;
        cout << "Usage: graph <size> <xstep> <ystep> <filename>" << endl;
}

int main(int argc, char** argv) {
    if (argc == 1) { usage(); return 0; } 
    if (argc != 4 and argc != 5) {usage(); return 0;}
    
    int size = stoi(argv[1]);
    int *values;

    if (argc == 4) {
        values= new int[size + size + 1];
        double step = stof(argv[2]);
        string function = argv[3];
        make_values(size, step, values, function);
    } else {

        double xstep = stof(argv[2]);
        double ystep = stof(argv[3]);
        string filename = argv[4];
        
        ifstream in(filename, ifstream::ate | ifstream::binary);
        values = new int[in.tellg()];
        cout << "Reading file..." << endl;
        read_file(size, xstep, ystep, values, filename);
    }

    margin(size);
    cout << title << endl;
  
    plot_upper(size, values, line, graph, axis);
    plot_center(size, values, line, axis);
    cout << y_label << endl;
    plot_lower(size, values, line, graph, axis);
    cout << x_label << endl;
    delete[] values;
}
