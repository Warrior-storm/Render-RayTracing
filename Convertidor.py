import os 
try:
    from PIL import Image
    print("Pillow está instalado correctamente.")
except ImportError:
    print("Pillow no está instalado.")

def convert_images(input_folder, output_folder):
    # Crear la carpeta de salida si no existe
    if not os.path.exists(output_folder):
        os.makedirs(output_folder)
    
    # Obtener la lista de archivos en la carpeta de entrada
    for filename in os.listdir(input_folder):
        if filename.endswith(".ppm"):
            # Ruta completa del archivo de entrada
            input_path = os.path.join(input_folder, filename)
            
            # Abrir la imagen PPM
            with Image.open(input_path) as img:
                # Crear la ruta completa del archivo de salida
                output_path = os.path.join(output_folder, os.path.splitext(filename)[0] + ".png")
                
                # Guardar la imagen en formato PNG
                img.save(output_path, "PNG")
    
    print(f"Conversión completada. Las imágenes se han guardado en {output_folder}")

if __name__ == "__main__":
    import sys
    if len(sys.argv) != 3:
        print("Uso: python Convertidor.py <carpeta_entrada> <carpeta_salida>")
        sys.exit(1)
    
    input_folder = sys.argv[1]
    output_folder = sys.argv[2]
    
    convert_images(input_folder, output_folder)