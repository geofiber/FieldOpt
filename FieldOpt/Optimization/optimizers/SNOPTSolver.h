//
// Created by bellout on 2/10/18.
//

#ifndef FIELDOPT_SNOPTSOLVER_H
#define FIELDOPT_SNOPTSOLVER_H

#include "Optimization/optimizer.h"

//#include "FieldOpt-3rdPartySolvers/include/snopt/snopt.hpp"
//included in snopt.hpp: #include "FieldOpt-3rdPartySolvers/include/snopt/f2c.h"

#include "FieldOpt-3rdPartySolvers/handlers/SNOPTLoader.h"
//included in SNOPTLoader.h: #include "FieldOpt-3rdPartySolvers/include/snopt/snopt.hpp"

//included in SNOPTHandler.h: #include "FieldOpt-3rdPartySolvers/include/snopt/snopt.hpp"
#include "FieldOpt-3rdPartySolvers/handlers/SNOPTHandler.h"

namespace Optimization {
namespace Optimizers {

#ifdef __cplusplus
extern "C" {
#endif
int SNOPTusrFG_( integer    *Status, integer *n,    doublereal x[],
                 integer    *needF,  integer *neF,  doublereal F[],
                 integer    *needG,  integer *neG,  doublereal G[],
                 char       *cu,     integer *lencu,
                 integer    iu[],    integer *leniu,
                 doublereal ru[],    integer *lenru);
#ifdef __cplusplus
}
#endif

class SNOPTSolver : public Optimizer {
 public:

  SNOPTSolver(::Settings::Optimizer *settings,
              Case *base_case,
              Model::Properties::VariablePropertyContainer *variables,
              Reservoir::Grid::Grid *grid,
              Logger *logger);

  ~SNOPTSolver();

  QString GetStatusStringHeader() const {};
  QString GetStatusString() const {};

 private:

  bool loadSNOPT(string libname = "libsnopt-7.2.12.2.so");
  SNOPTHandler initSNOPTHandler();
  void setOptionsForSNOPT(SNOPTHandler& snoptHandler_);

  void callSNOPT();



  void iterate() {};
  bool is_successful_iteration(){};

  void handleEvaluatedCase(Case *c) override {};
  TerminationCondition IsFinished() {};



};

}
}

#endif //FIELDOPT_SNOPTSOLVER_H