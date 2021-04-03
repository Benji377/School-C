#ifndef __FIBONACCI_H__
#define __FIBONACCI_H__

int fibbonacci(int n) {
    if(n == 0){
        return 0;
    } else if(n == 1) {
        return 1;
    } else {
        return (fibbonacci(n-1) + fibbonacci(n-2));
    }
}

#endif //C_PROJECTS_FIBONACCI_H
