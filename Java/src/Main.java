import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.math.BigInteger;
import java.util.StringTokenizer;
import java.util.Vector;

public class Main {
  static BigInteger f(String s, int n) {
    Vector<Vector<BigInteger>> dp = new Vector<>(n + 1);
    for (int i = 0; i <= n; i++) {
      dp.add(new Vector<>(9));
      for (int j = 0; j < 9; j++) {
        dp.get(i).add(BigInteger.ZERO);
      }
    }

    dp.get(n).set(0, BigInteger.ONE);

    for (int pos = n - 1; pos >= 0; --pos) {
      if (s.charAt(pos) != '?') {
        int digit = Character.getNumericValue(s.charAt(pos));
        for (int rem = 0; rem < 9; ++rem) {
          dp.get(pos).set(rem, dp.get(pos + 1).get((rem - digit + 9) % 9));
        }
      } else {
        for (int rem = 0; rem < 9; ++rem) {
          for (int i = (pos == 0) ? 1 : 0; i < 10; ++i) {
            dp.get(pos).set(rem, dp.get(pos).get(rem).add(dp.get(pos + 1).get((rem - i + 9) % 9)));
          }
        }
      }
    }
    return dp.get(0).get(0);
  }

  public static void main(String[] args) throws IOException {
    BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
    BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out));

    int tt = 1, tc = 0;
    try {
      tt = Integer.parseInt(reader.readLine().trim());
    } catch (NumberFormatException e) {
      e.printStackTrace();
      return;
    }

    while (tt-- > 0) {
      tc++;
      try {
        int n = Integer.parseInt(reader.readLine().trim());
        String s = reader.readLine().trim();
        writer.write(f(s, n).toString());
        writer.newLine();
      } catch (NumberFormatException | StringIndexOutOfBoundsException e) {
        e.printStackTrace();
        return;
      }
    }

    writer.flush();
  }
}