# Modelos

## Modelos sin shocks

### Modelo_B.ma

Modelo con las reglas descriptas originalmente en el TP de  Dima. Salvo que los partidarios entre si se repelen como son descriptos por Balenzuela.

### Modelo_B_k.ma

Basado en el Modelo_A.ma pero en el caso de una celda que indefinida que observa una partidaria se mueve k*delta en la dirección del partidario.

### Modelo_D.ma

Modelo con las reglas descriptas originalmente en el TP de  Dima. Los partidarios entre tienen 50% de posibilidades de atraers.

### Modelo_D_k.ma
Basado en el Modelo_D.ma pero en el caso de una celda que indefinida que observa una partidaria se mueve k*delta en la dirección del partidario.

### Modelo_D_k_I.ma

Basado en el Modelo_D_k.ma, pero que incluye reglas de Influyentes (TPF de Dima).

## Modelos con shocks

### Model_D_k_I_shock.ma

Basado en el Modelo_D_k_I.ma con shocks (TP2 Rodriguez-Modrow-Foguelman).

### Model_B_shock.ma

Basado en Model_B con shocks. Estos shocks los modifican el valor de la celda, independiente del valor en el momento de la celda (según lo definido en el TP2 Rodriguez-Modrow-Foguelman).

### Model_D_shock.ma

Basado en Model_D con shocks. Estos shocks los modifican el valor de la celda, independiente del valor en el momento de la celda (según lo definido en el TP2 Rodriguez-Modrow-Foguelman).

### Model_B_qshock_3x3.ma

Modelo de shock para probar reglas de tratamiento de los shock, modificar en | q_shock * delta | el valor de la celda, por medio de la definición de PortInTransition para cada celda.

### Model_B_qshock.ma

Basado en Model_B con shocks que modifican el estado de la celda en |q_shock * delta|. Dependiendo del valor de la celda y el valor del shock se determina si es + ó -.

### Model_D_qshock.ma

Basado en Model_B con shocks que modifican el estado de la celda en |q_shock * delta|. Dependiendo del valor de la celda y el valor del shock se determina si es + ó -.
