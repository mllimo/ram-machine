# Practica 2: Máquina RAM

## Compilación

Para poder compilar este proyecto tendrá que tener cmake. Si ya lo tiene Abra una terminal, cree una carpeta denominada *build* en la raíz del proyecto y dentro de ella escriba:
```cmake -DCMAKE_BUILD_TYPE=Release  ..``` Luego ejecute ```make ram_sim```

### Tests

Para poder compilar los test tendrá que tener instalado GoogleTest. Si ya lo tiene, dentro del paso anterior use ```make tests```

## Programas RAM

Los programas de la máquina estarán almacenados dentro de la carpeta `test/rams`
