#include <stdio.h>
#include "../src/carrito.h"
#include "minunit/minunit.h"

/*
 * Tests de integracion: verifican que las funciones trabajan bien
 * en combinacion, no de forma aislada.
 */

/* ═══════════════════════════════════════════════════════════════════════════
 *  PARTE D — Escribir el test guiado (ver README.md, Parte 8)
 * ═══════════════════════════════════════════════════════════════════════════ */

    void test_compra_con_descuento() {
        printf("\n[=== test_compra_con_descuento ===]\n");
        Carrito c;
        carrito_init(&c);
        Producto p1 = {"Pan", 200, 3};  /* 3 panes a $200 cada uno, subtotal = $600 */
        carrito_agregar(&c, p1);
        Producto p2 = {"Leche", 350, 2}; /* 2 leches a $350 cada una, subtotal = $700 */
        carrito_agregar(&c, p2);
        ASSERT_IGUAL(1300, carrito_total(&c)); /* total = $600 + $700 = $1.300 */
        int porcDescuento = 10; /* 10% de descuento */
        ASSERT_IGUAL(1170, carrito_descuento(carrito_total(&c), porcDescuento)); /* total final = $1.170 */
    }

/* TODO: escribir test_compra_con_descuento() siguiendo la guia del .md */

/* ═══════════════════════════════════════════════════════════════════════════
 *  PARTE E — Disenar un test propio (ver README.md, Parte 9)
 * ═══════════════════════════════════════════════════════════════════════════ */

    void test_agregar_hasta_llenar(){
        printf("\n[=== test_agregar_hasta_llenar ===]\n");
        Carrito c;
        carrito_init(&c);
        for(int i = 0; i < MAX_ITEMS; i++){
            Producto i = {"Producto", 100, 1};
            carrito_agregar(&c, i);
        };
        ASSERT_IGUAL(MAX_ITEMS, carrito_contar(&c));
        ASSERT_VERDADERO(carrito_agregar(&c, (Producto){"Extra", 100, 1}) == 0);
        ASSERT_IGUAL(MAX_ITEMS, carrito_contar(&c));
    }

/* TODO: escribir test_agregar_hasta_llenar() */

int main(void) {
    printf("=== Tests de integracion ===");
    /* Descomentar a medida que agregues las funciones: */
    test_compra_con_descuento();
    test_agregar_hasta_llenar();
    RESUMEN();
    return EXIT_CODE();
}
