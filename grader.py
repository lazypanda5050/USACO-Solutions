import subprocess
import sys
import zipfile
import shutil
import tempfile
from pathlib import Path

# ===========================
# CONFIGURATION
# ===========================
cpp_file = "2017_jan_bronze_p2"        # Added .cpp extension
zip_path = "./Test\ Data/2017_jan_bronze_p2.zip" # Path to your zip file
timeout_seconds = 2
exe_file = "2025.exe" if sys.platform == "win32" else "./solution"

# ===========================
# COMPILE THE C++ FILE
# ===========================
compile_cmd = ["g++", "-std=c++17", "-O2", cpp_file, "-o", exe_file]
print(f"Compiling {cpp_file}...")
result = subprocess.run(compile_cmd, capture_output=True, text=True)
if result.returncode != 0:
    print("Compilation failed:")
    print(result.stderr)
    sys.exit(1)
print("Compilation successful!\n")

# ===========================
# RUN TESTS FROM ZIP
# ===========================
# Create a temporary directory to extract files into
with tempfile.TemporaryDirectory() as temp_dir:
    temp_path = Path(temp_dir)
    
    print(f"Extracting {zip_path}...")
    try:
        with zipfile.ZipFile(zip_path, 'r') as zip_ref:
            zip_ref.extractall(temp_dir)
    except FileNotFoundError:
        print(f"Error: Could not find {zip_path}")
        sys.exit(1)

    # USACO zips often have a folder inside the zip. 
    # This finds all .in files regardless of how deep they are.
    in_files = sorted(list(temp_path.rglob("*.in")), key=lambda f: f.stem.zfill(5))

    if not in_files:
        print("No .in files found inside the zip.")
        sys.exit(1)

    for in_file in in_files:
        out_file = in_file.with_suffix(".out")
        if not out_file.exists():
            continue

        print(f"Testing {in_file.name}...", end=" ", flush=True)

        try:
            with open(in_file, "r") as f_in:
                proc = subprocess.run(
                    [exe_file],
                    stdin=f_in,
                    capture_output=True,
                    text=True,
                    timeout=timeout_seconds
                )
            
            actual = proc.stdout.strip()
            with open(out_file, "r") as f_out:
                expected = f_out.read().strip()

            if actual == expected:
                print("✅ PASS")
            else:
                print("❌ FAIL")
                print(f"\n--- Expected ---\n{expected}\n--- Actual ---\n{actual}\n")
                break # Stop on first failure

        except subprocess.TimeoutExpired:
            print("⏰ TIMEOUT")
            break