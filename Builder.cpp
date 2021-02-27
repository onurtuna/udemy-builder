namespace Product {
   namespace Parts {
       class Vehicle {
       public:
           std::string type;
       };

       class Clan {
       public:
           std::string name;
       };

       class Weapons {
       public:
           std::vector<std::string> list;
       };
   }

   class Transformer {
   public:
       Parts::Vehicle *vehicle;
       Parts::Clan *clan;
       Parts::Weapons *weapons;

       void getSpecs() {
           std::cout << "Vehicle: " << vehicle->type << std::endl;
           std::cout << "Clan: " << clan->name << std::endl;
           std::cout << "Weapons: " << std::endl;
           for (auto it : weapons->list) {
               std::cout << it << std::endl;
           }
       };
   };
}

namespace Builder {
   class Engineer {
   public:
       virtual Product::Parts::Vehicle* getVehicle() = 0;
       virtual Product::Parts::Clan* getClan() = 0;
       virtual Product::Parts::Weapons* getWeapons() = 0;
   };

   class OptimusPrimeEngineer : public Engineer {
   public:
       Product::Parts::Vehicle *getVehicle() {
           Product::Parts::Vehicle *vehicle = new Product::Parts::Vehicle();
           vehicle->type = "tir";
           return vehicle;
       }

       Product::Parts::Clan *getClan() {
           Product::Parts::Clan *clan = new Product::Parts::Clan();
           clan->name = "Autobot";
           return clan;
       }

       Product::Parts::Weapons *getWeapons() {
           Product::Parts::Weapons *weapons = new Product::Parts::Weapons();
           weapons->list.push_back("energy ax");
           weapons->list.push_back("laser ball");
           return weapons;
       }
   };

   class MegatronEngineer : public Engineer {
   public:
       Product::Parts::Vehicle *getVehicle() {
           Product::Parts::Vehicle *vehicle = new Product::Parts::Vehicle();
           vehicle->type = "airplane";
           return vehicle;
       }

       Product::Parts::Clan *getClan() {
           Product::Parts::Clan *clan = new Product::Parts::Clan();
           clan->name = "Decepticon";
           return clan;
       }

       Product::Parts::Weapons *getWeapons() {
           Product::Parts::Weapons *weapons = new Product::Parts::Weapons();
           weapons->list.push_back("fusion cannon");
           return weapons;
       }
   };
}

class Director {
   Builder::Engineer *engineer;

public:
   void setEngineer(Builder::Engineer *newEngineer) {
       engineer = newEngineer;
   }

   Product::Transformer *getSpecs() {
       Product::Transformer *transformer = new Product::Transformer();
       transformer->vehicle = engineer->getVehicle();
       transformer->clan = engineer->getClan();
       transformer->weapons = engineer->getWeapons();
       return transformer;
   }
};

int main()
{
   Product::Transformer *transformer;

   Director director;

   Builder::OptimusPrimeEngineer optimusPrimeEngineer;
   Builder::MegatronEngineer megatronEngineer;

   std::cout << "Optimus Prime" << std::endl;
   director.setEngineer(&optimusPrimeEngineer);
   transformer = director.getSpecs();
   transformer->getSpecs();

   std::cout << std::endl;

   std::cout << "Megatron" << std::endl;
   director.setEngineer(&megatronEngineer);
   transformer = director.getSpecs();
   transformer->getSpecs();

   return 0;
}

