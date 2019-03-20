package main
import "fmt"

func divide_unsign(dividend int, divisor int) int {
  var i = 0
  var c = 1
  var sub = divisor
  for;dividend >= divisor;{
    if( dividend >= sub){
      dividend -= sub
      i += c
      sub = (sub << 1)
      c = (c<<1)
    }else
    {
      sub = (sub>>1)
      c = (c>>1)
    }
  }
  return i
}
func Abs(x int) int {
  if x < 0 {
    return -x
  }
  return x
}
func divide(dividend int, divisor int) int {
  var sign = (dividend>0) && (divisor < 0) || (dividend < 0)  && (divisor >0)
  if sign{
    return -1*divide_unsign(Abs(dividend),Abs(divisor))
  }else{
    var res=divide_unsign(Abs(dividend),Abs(divisor))
    if( res == 2147483648){
      return 2147483647
    }else{
      return res
    }    
		}		
}    
func main() {
	fmt.Println(divide(10,3))
	fmt.Println(divide(7,-3))
	fmt.Println(divide(1,1))
	fmt.Println(divide(-2147483648,-1))
	fmt.Println(divide(-2147483648,1))
	fmt.Println(divide(-100,-1))
	fmt.Println(divide(-999511578,-2147483648))
}