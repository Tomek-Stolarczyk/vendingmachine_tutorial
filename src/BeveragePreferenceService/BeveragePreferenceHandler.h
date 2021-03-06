#ifndef VENDING_MACHINE_MICROSERVICES_BEVERAGEPREFERENCEHANDLER_H
#define VENDING_MACHINE_MICROSERVICES_BEVERAGEPREFERENCEHANDLER_H

#include <iostream>
#include <string>
#include <regex>
#include <future>

#include "../../gen-cpp/BeveragePreferenceService.h"

#include "../ClientPool.h"
#include "../ThriftClient.h"
#include "../logger.h"

namespace vending_machine{

class BeveragePreferenceServiceHandler : public BeveragePreferenceServiceIf {
 public:
  BeveragePreferenceServiceHandler() = default;
  ~BeveragePreferenceServiceHandler() override=default;

  void getBeverage(std::string& _return, const BeverageType::type beverage_type) override;
};

// Remote Procedure "getBeverage"
void BeveragePreferenceServiceHandler::getBeverage(std::string& _return, const BeverageType::type beverage_type){
   // Your implementation goes here
   printf("getBeverage\n");
   if(beverage_type == BeverageType::type::COLD) _return = "Coke";
   else _return  = "warm coke";

   return;
}

} // namespace vending_machine


#endif //VENDING_MACHINE_MICROSERVICES_BEVERAGEPREFERENCEHANDLER_H

