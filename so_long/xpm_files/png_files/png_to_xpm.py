from PIL import Image
import glob
import os

for file in glob.glob("*.png"):
    img = Image.open(file)
    xpm_name = os.path.splitext(file)[0] + ".xpm"
    img.save(xpm_name)
    print(f"Converted: {file} -> {xpm_name}")
