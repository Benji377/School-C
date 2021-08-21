#ifndef C_PROJECTS_MATRIX_H
#define C_PROJECTS_MATRIX_H


typedef
struct matrix_s {
    int zeilen;
    int spalten;
    double matrix[10][10];
} matrix_t;

matrix_t matrix_add(matrix_t a, matrix_t b) {
    matrix_t ret;
    for(int i = 0; i <= a.spalten; i++) {
        for(int j = 0; j <= a.zeilen; j++) {
            ret.matrix[i][j] = a.matrix[i][j] + b.matrix[i][j];
        }
    }
    return ret;
}

matrix_t matrix_sub(matrix_t a, matrix_t b) {
    matrix_t ret;
    for(int i = 0; i <= a.spalten; i++) {
        for(int j = 0; j <= a.zeilen; j++) {
            ret.matrix[i][j] = a.matrix[i][j] - b.matrix[i][j];
        }
    }
    return ret;
}

matrix_t matrix_mult_num(matrix_t a, double num) {
    matrix_t ret;

    for(int i = 0; i <= a.spalten; i++) {
        for(int j = 0; j <= a.zeilen; j++) {
            ret.matrix[i][j] = a.matrix[i][j] * num;
        }
    }

    return ret;
}

matrix_t matrix_mult_matrix(matrix_t a, matrix_t b) {
    matrix_t ret;

    for(int i = 0; i <= a.spalten; i++) {
        for(int j = 0; j <= a.zeilen; j++) {
            for(int k = 0; k < a.zeilen; k++) {
                ret.matrix[i][j] = a.matrix[i][k]*b.matrix[k][j];
            }
        }
    }
    return ret;
}



// Multiplikation mit anderer Matrix oder nur einzelne Zahl?

// Division von Matrix durch Multplikation vom Kehrwert!


#endif //C_PROJECTS_MATRIX_H
