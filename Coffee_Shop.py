class Menu:
    coffee_type=["Espresso","Cappuccino","Latte"]
    add_ons=["Milk","Cream","Latte"]
    cost={"Espresso + Milk": 60,
          "Espresso + Cream": 75,
          "Espresso + Latte": 100,
          "Cappuccino + Milk": 80,
          "Cappuccino + Cream": 90,
          "Cappuccino + Latte": 125,
          "Latte + Milk": 100,
          "Latte + Cream": 125,
          "Latte + Latte": 150}
    
    
    def getCoffeeName(self,user_option):
        return self.coffee_type[user_option-1]
    
    def getAddOnName(self,user_option):
        return self.add_ons[user_option-1]
    
    def getPrice(self,product):
        return self.cost[product]
    
    
class CoffeeShop(Menu):    
    cart={}
    def _init_(self):
        print("Welcome to CoffeeShop!") 
                
    def displayMenu(self):
        print("Available Coffee Types:")
        for i,coffee in enumerate(self.coffee_type):
            print("{0}. {1}".format(i+1,coffee))
        print("Available Add-ons:")
        for i,item in enumerate(self.add_ons):
            print("{0}. {1}".format(i+1,item))
        print("Available Combinations:")
        i=1
        for product,price in self.cost.items():
            print("{0}. {1} : Rs. {2}".format(i,product,price))
            i+=1
        self.getUserChoice()
    
    def getUserChoice(self):
        #get falvour
        coffee_flavour_num=int(input("Enter the coffee type(1-3):\n"))
        while coffee_flavour_num>3:
            print("Invalid option! Choose number between (1-3)")
            coffee_flavour_num=int(input("Enter the coffee type(1-3):\n"))
        coffee_flavour=self.getCoffeeName(coffee_flavour_num)
            
        #get addon
        add_on_num=int(input("Enter the add-on(1-3):\n"))
        while add_on_num>3:
            print("Invalid option! Choose number between (1-3)")
            add_on_num=int(input("Enter the add-on(1-3):\n"))
        add_on=self.getAddOnName(add_on_num)
        
        #get quantity:
        quantity=int(input("Quantity (no of coffees you want):\n"))
        product="{0} + {1}".format(coffee_flavour,add_on)
        
        if product in self.cart:
            self.cart[product]+=quantity
        else:
            self.cart[product]=quantity
        
        print(self.cart)
        option=input("Would you like to order another coffee:\nType 'y' for yes and 'n' for no\n")
        if option=="y":
            self.displayMenu()
        else:
            self.calculateBill()
    
    def calculateBill(self):
        total_amount=0
        print("\nBILL:")
        for item,quantity in self.cart.items():
            product_price=self.getPrice(item)
            amt=product_price*quantity
            print("Coffee Combo  : {0}".format(item))
            print("Price         : {0}".format(product_price))
            print("Quantity      : {0}".format(quantity))
            total_amount+=amt
            
        print("Total Amount to be Paid: Rs.{0}".format(total_amount))
        
    

shop=CoffeeShop()
shop.displayMenu()