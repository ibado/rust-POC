echo "compiling code..."
TIMEFORMAT="time: %R seconds"

cd rust && cargo build --release &> /dev/null
cd ../c && make &> /dev/null
cd ../kotlin && kotlinc Words.kt
echo ""

echo "Running Kotlin..."
time kotlin Words ../test.txt si
echo ""

echo "Running C..."
cd ../c
time ./main ../test.txt si
echo ""

echo "Running Rust..."
cd ../rust && time target/release/rust-benchmark ../test.txt si

cd ..
