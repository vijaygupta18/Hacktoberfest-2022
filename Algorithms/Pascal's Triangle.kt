object PascalsTriangle {
  fun computeTriangle(n: Int): List<List<Int>> {
    require(n >= 0) { "Rows can not be negative!!" }
    return when (n) {
      0 -> listOf<List<Int>>()
      else -> (2..n).fold(listOf(listOf(1))) { acc, _ ->
        acc.plusElement(listOf(1) + acc.last().zipWithNext(Int::plus) + listOf(1))
      }
    }
  }
}

fun main(){

  print(PascalsTriangle.computeTriangle(10))

}
