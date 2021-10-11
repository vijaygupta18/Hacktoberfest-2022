# TECHIE LIBRARY
class Library:
    genres= []
    total_books=[]
    books=[]
    register={}
    def __init__(self,x,y):
        self.book_list = x
        self.genre= y
        Library.genres.append(self.genre)
        Library.books.extend(self.book_list)
        Library.total_books.extend(self.book_list)

    @classmethod
    def display_book_in_Lib(cls):
        return cls.total_books

    def display_book_for_one(self):
        return self.book_list

    @classmethod
    def display_genres_in_Lib(cls):
        return cls.genres

    @classmethod
    def lend_book(cls):
        borrow_name = input("Enter your name.")
        book_name = input("Enter the name of the book you want to borrow.")
        if book_name in Library.total_books:
            if book_name in Library.books:
                print(f"Lending book - {book_name}")
                Library.books.remove(book_name)
                Library.register[book_name]=borrow_name
            else:
                print(f"Book is already borrowed by {Library.register[book_name]}.")
        else:
            print("Book not found in Library.")

    @classmethod
    def add_book(cls):
        book_name = input("Enter the name of the book you want to add.")
        Library.total_books.append(book_name)
        Library.books.append(book_name)
        return book_name
    @classmethod
    def return_book(cls):
        book_name = input("Enter the name of the book you want to return.")
        Library.books.append(book_name)
        Library.register.pop(book_name)

    @classmethod
    def takeback_book(cls):
        book_name = input("Enter name of book you want to take back.")
        Library.total_books.remove(book_name)
        Library.books.remove(book_name)

history= Library(["Sapiens:A brief history of mankind",
                  "India's ancient past",
                  "Genghis khan and the Making of The modern world"]
                 , "History")
english_novels= Library(["Twillight in Delhi",
                  "The palace of illusions",
                  "Immortals of Meluha"]
                 , "English Novels")
hindi_novels= Library(["Godan",
                       "Gaban",
                       "Raag Darbari",
                       "Maila Aanchal"
                       "Ahal"],
                      "Hindi novels")
science_fictions = Library(["Frankenstein",
                            "Brave New World",
                            "The Time Machine",
                            "The left Hand Of darkness"]
                           , "Science fictions")
donated_books = Library([],"Donated Books")
print("WELCOME TO OUR LIBRARY\nHere you can borrow any book from the collection we have,\n"
      "Return the book you lended earlier,\nAnd even donate books so that others can enjoy them too")

while True:
    action= input("\nEnter A for Displaying the Library's collection\n"
                  "Enter B for Borrowing a book\n"
                  "Enter C for Returning a lended book\n"
                  "Enter D for Donating a book\n"
                  "Enter E for Taking back a Donated book\n"
                  "Enter F for Ending your Library session\n")
    if action== "A":
        display= input("Enter A for Displaying all the books in library\n"
                       "Enter B for Displaying all the genres in library\n")
        if display== "A":
            print(Library.display_book_in_Lib())
        elif display== "B":
            print(Library.display_genres_in_Lib())
            display2= input("Enter A if you want to see books of any paricular genre\n"
                            "Enter B to end for any other activity you want to perform\n")
            if display2== "A":
                genre2= input("Enter A for History genre\n"
                              "Enter B for English novels\n"
                              "Enter C for Hindi novels\n"
                              "Enter D for Science fictions\n"
                              "Enter E FOR Donated books\n")
                if genre2=="A":
                    print(history.display_book_for_one())

                if genre2 == "B":
                    print(english_novels.display_book_for_one())

                if genre2 == "C":
                    print(hindi_novels.display_book_for_one())

                if genre2 == "D":
                    print(science_fictions.display_book_for_one())

                if genre2 == "E":
                    print(donated_books.display_book_for_one())

            elif display2=="B":
                continue
    if action=="B":
        Library.lend_book()
        continue

    if action=="C":
        Library.return_book()
        print("Thanks for returning :)")
        continue

    if action== "D":
        donated_books.book_list.append(Library.add_book())
        print("Thanks for donating :)")
        continue

    if action== "E":
        Library.takeback_book()
        continue

    elif action=="F":
        print("Thanks for visiting!")
        break

print("HAPPY READING !!")
