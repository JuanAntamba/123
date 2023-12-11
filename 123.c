#include <stdio.h>

// Definir constantes
#define ALUMNOS 23
#define PROGRESOS_SEMESTRE 3

// Función para obtener el promedio de un alumno
float obtenerPromedioAlumno(float calificaciones[PROGRESOS_SEMESTRE]) {
    float suma = 0;
    for (int i = 0; i < PROGRESOS_SEMESTRE; i++) {
        suma += calificaciones[i];
    }
    return suma / PROGRESOS_SEMESTRE;
}

// Función para obtener el promedio del grupo para un progreso específico
float obtenerPromedioProgreso(float calificaciones[ALUMNOS][PROGRESOS_SEMESTRE], int progreso) {
    float suma = 0;
    for (int i = 0; i < ALUMNOS; i++) {
        suma += calificaciones[i][progreso];
    }
    return suma / ALUMNOS;
}

// Función para obtener el número del mejor alumno
int obtenerMejorAlumno(float calificaciones[ALUMNOS][PROGRESOS_SEMESTRE]) {
    int mejorAlumno = 0;
    float mayorPromedio = 0;

    for (int i = 0; i < ALUMNOS; i++) {
        float promedioAlumno = obtenerPromedioAlumno(calificaciones[i]);
        if (promedioAlumno > mayorPromedio) {
            mayorPromedio = promedioAlumno;
            mejorAlumno = i;
        }
    }

    return mejorAlumno + 1; // Sumar 1 para ajustar el índice base 0 a base 1
}

int main() {
    // Declarar variables
    float calificaciones[ALUMNOS][PROGRESOS_SEMESTRE];
    float promedioAlumno, promedioProgreso;
    int mejorAlumno;

    // Leer calificaciones de los alumnos
    for (int i = 0; i < ALUMNOS; i++) {
        printf("Ingrese las calificaciones del alumno %d:\n", i + 1);
        for (int j = 0; j < PROGRESOS_SEMESTRE; j++) {
            scanf("%f", &calificaciones[i][j]);
        }
    }

    // Calcular y imprimir el promedio de cada alumno
    for (int i = 0; i < ALUMNOS; i++) {
        promedioAlumno = obtenerPromedioAlumno(calificaciones[i]);
        printf("El promedio del alumno %d es: %f\n", i + 1, promedioAlumno);
    }

    // Calcular y imprimir el promedio del grupo para cada progreso
    for (int j = 0; j < PROGRESOS_SEMESTRE; j++) {
        promedioProgreso = obtenerPromedioProgreso(calificaciones, j);
        printf("El promedio del grupo para el progreso %d es: %f\n", j + 1, promedioProgreso);
    }

    // Encontrar e imprimir al mejor alumno
    mejorAlumno = obtenerMejorAlumno(calificaciones);
    printf("El mejor alumno es el número %d\n", mejorAlumno);

    return 0;
}
