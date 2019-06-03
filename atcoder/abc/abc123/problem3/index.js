const getR = () => Math.round((Math.random() * 10000) % 1000);

const f1 = (n, m) => Math.round((n + m - 1) / m) + 4;
const f2 = (n, m) => Math.round(n / m) + 5;

for (i = 0; i <= 1000; i++) {
  const n = getR();
  const m = getR();
  if (f1(n, m) != f2(n, m)) {
    console.log(n, ":", m);
    console.log(n % m);
    console.log(f1(n, m), "- ", f2(n, m));
  }
}
