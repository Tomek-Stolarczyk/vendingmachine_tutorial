#ifndef VENDING_MACHINE_MICROSERVICES_BEVERAGEPREFERENCEHANDLER_H
#define VENDING_MACHINE_MICROSERVICES_BEVERAGEPREFERENCEHANDLER_H

#include <iostream>
#include <string>
#include <regex>
#include <future>
#include <array>

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

   const std::array<const char*, 3> warm_drinks = {"cappuccino", "latte", "espresso"};
   const std::array<const char*, 3> cold_drinks = {"lemonade", "ice tea", "soda"};

   const auto& drink_selection = (beverage_type == BeverageType::type::COLD) ? warm_drinks : cold_drinks;

   _return = drink_selection[rand() % drink_selection.size()];

   return;
}

} // namespace vending_machine


#endif //VENDING_MACHINE_MICROSERVICES_BEVERAGEPREFERENCEHANDLER_H

