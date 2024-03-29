#ifndef TP3_BASEDEDATOS_H
#define TP3_BASEDEDATOS_H

#include "modulos_basicos/string_map.h"

#include "Tabla.h"
#include "Tipos.h"
#include "Registro.h"
#include <list>

class BaseDeDatos {
public:
    BaseDeDatos() : _tables() {};

    /**
     * Returns a set with all contained nameTables
     * Time complexity: O(1)
     * */
    const linear_set<NombreTabla> &tablas() const;

    /**
     * Returns the table associated with the name
     * Pre = {_tables.count(tableName) > 0}
     * Time complexity: O(1)
     * */
    const Tabla &obtenerTabla(const NombreTabla &tableName) const;

    /**
     * Adds a table with tableName as key and table as value
     * Time complexity: O(name.size + copy(table))
     * */
    void agregarTabla(const NombreTabla &tableName, Tabla table);

    /**
     * Erases the table associated with tableName
     * Time complexity: O(name.size + k * BorarRegistro(tableName, k_i))
     * with k being the amount of registers in the table
     * and k_i every register in the table
     * */
    void borrarTabla(const NombreTabla &tableName);

    /**
     * Adds the reg in the table associated with tableName
     * Time complexity: O(tableName.size + reg.size * (f.size + v.size))
     * reg.size = O(1), with f being the longest field and v being the longest value
     * */
    void agregarRegistro(const NombreTabla &tableName, Registro reg);

    /**
     * Erases the reg in the table associated with tableName
     * Time complexity: O(tableName.size + reg.size * f.size)
     * reg.size = O(1), with f being the longest field
     * */
    void borrarRegistro(const NombreTabla &tableName, Registro reg);

private:
    string_map<Tabla> _tables;

};

#endif //TP3_BASEDEDATOS_H
