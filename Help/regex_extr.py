from re import findall
from subprocess import call

def counter():
    """Leer un texto, debe contar la cantidad de Vocales, mayúsculas, Minúsculas, números y caracteres especiales"""
    call("cls", shell=True)
    user_text = input("Ingrese: ")
    lower_vowels = len(findall("[aeiuo]+?", user_text)) # ? = separa las vocales por texto en elementos diferentes
    upper_vowels = len(findall("[AEIOU]+?", user_text))
    numbers = len(findall("[1-9]+", user_text)) # No separa los numeros unidos, ya que es un numero
    specials = len(findall("[#!¡?\"$%&/\]\[=\(\)*¨_\-+}{´]+?", user_text)) # )!#\"$%&/\]\[(=?¡*¨_-´}+{
    
    print("En total fueron")
    if lower_vowels >= 1:
        print(f"Vocales minúsculas: {lower_vowels}")
    if upper_vowels >= 1:
        print(f"Vocales mayúsculas: {upper_vowels}")
    if numbers >= 1:
        print(f"Numeros: {numbers}")
    if specials >= 1:
        print(f"Carácteres especiales: {specials}")
    input("")
    counter()

counter()
