// fecha.h - Declaración de la clase CFecha
#if !defined( _FECHA_H_ )
#define _FECHA_H_

class CFecha
{
  // Atributos
  private:
    int dia, mes, anyo;
    static CFecha fechaPorOmision; // se inicia en fecha.cpp
  // Métodos
  protected:
    bool bisiesto() const;
  public:
    CFecha(int dd = 1, int mm = 1, int aaaa = 2001); // constructor
    void asignarFecha(int dd = 0, int mm = 0, int aaaa = 0);
    void obtenerFecha(int& dd, int& mm, int& aaaa) const;
    bool fechaCorrecta() const;
    const int& obtenerDia() const;
    const int& obtenerMes() const;
    const int& obtenerAnyo() const;
    static void asignarFechaPorOmision(int = 0, int = 0, int = 0);
    static void obtenerFechaActual(int&, int&, int&);
};

#endif // _FECHA_H_
