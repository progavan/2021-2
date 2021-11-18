/** ABEntry.h - Declaraci\'on de la clase ABEntry
 *  (Address Book Entry), derivada de la clase
 *  Directory_Entry
 */
#ifndef ABENTRY_H
#define ABENTRY_H

#include <Directory_Entry.h>

/** Clase derivada de Directory_Entry */
class ABEntry : public Directory_Entry
{
public:
  ABEntry();
  ABEntry(const std::string& nombre,
          const std::string& numero,
          const std::string& domicilio);
  std::string get_domicilio();
  void set_domicilio(std::string domicilio);
  void update_num_TimesConsulted();
  int get_num_TimesConsulted();
protected:
  /** Domicilio de la entrada de Libro de
      direcciones
  */
  std::string elDomicilio;
  /** Cantidad de veces que los datos de
      la entrada han sido consultados
  */
  int num_TimesConsulted;
private:
};/*end class ABEntry */

#endif // ABENTRY_H
