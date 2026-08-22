#include <stdio.h>
#include "../src/carrito.h"
#include "minunit/minunit.h"

/* ═══════════════════════════════════════════════════════════════════════════
 *  TESTS ESCRITOS — ya funcionan, son el punto de partida
 * ═══════════════════════════════════════════════════════════════════════════ */

void test_carrito_nuevo(void) {
    printf("\n[carrito nuevo]\n");
    Carrito c;
    carrito_init(&c);
    ASSERT_IGUAL(0, carrito_contar(&c));
}

void test_agregar_uno(void) {
    printf("\n[agregar un producto]\n");
    Carrito c;
    carrito_init(&c);
    Producto p = {"Leche", 350, 1};
    ASSERT_IGUAL(1, carrito_agregar(&c, p));   /* devuelve 1 = exito */
    ASSERT_IGUAL(1, carrito_contar(&c));
}

/* ═══════════════════════════════════════════════════════════════════════════
 *  PARTE A — Agregar el siguiente test (ver README.md, Parte 4)
 * ═══════════════════════════════════════════════════════════════════════════ */

 void test_total_precio_unitario(void) {
    printf("\n[total: un producto, cantidad 1]\n");
    Carrito c;
    carrito_init(&c);
    Producto p = {"Leche", 350, 1};
    carrito_agregar(&c, p);
    ASSERT_IGUAL(350, carrito_total(&c));
}

/* TODO: pegar aqui la funcion test_total_precio_unitario() */

/* ═══════════════════════════════════════════════════════════════════════════
 *  PARTE B — Completar los blancos (ver README.md, Parte 5)
 * ═══════════════════════════════════════════════════════════════════════════ */

 void test_total_con_cantidad(void) {
    printf("\n[total: un producto, cantidad 2]\n");
    Carrito c;
    carrito_init(&c);
    Producto p = {"Leche", 350, 2};  /* 350 x 2 = 700 */
    carrito_agregar(&c, p);
    ASSERT_IGUAL(700, carrito_total(&c));  /* <-- completar el valor esperado */
}

/* TODO: pegar y completar la funcion test_total_con_cantidad() */

/* ═══════════════════════════════════════════════════════════════════════════
 *  PARTE C — Escribir un test propio (ver README.md, Parte 7)
 * ═══════════════════════════════════════════════════════════════════════════ */

    void test_carrito_lleno(void) {
        printf("\n[carrito lleno]\n");
        Carrito c;
        carrito_init(&c);
        Producto p1 = {"Jugo", 300, 1};
        Producto p2 = {"Jugo", 300, 1};
        Producto p3 = {"Jugo", 300, 1};
        Producto p4 = {"Jugo", 300, 1};
        /* Producto p5 = {"Jugo", 300, 1};  Producto extra que no entra en el carrito*/
        carrito_agregar(&c, p1);
        carrito_agregar(&c, p2);
        carrito_agregar(&c, p3);
        carrito_agregar(&c, p4);
        /* carrito_agregar(&c, p5);  este no deberia agregarse [cant = 4] */ 
        ASSERT_IGUAL(4, carrito_contar(&c)); 
    }

/* TODO: escribir test_carrito_lleno() */

/* ═══════════════════════════════════════════════════════════════════════════
 *  main
 * ═══════════════════════════════════════════════════════════════════════════ */

int main(void) {
    printf("=== Tests unitarios ===");
    test_carrito_nuevo();
    test_agregar_uno();
    /* Descomentar a medida que agregues las funciones: */
    test_total_precio_unitario(); 
    test_total_con_cantidad();
    test_carrito_lleno();
    RESUMEN();
    return EXIT_CODE();
}
