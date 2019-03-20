package main
import "fmt"
import "strings"

func lengthOfLastWord(s string) int {
  var i = 0
  var sum =0
  for i = len(s)-1; i >=0; i--{
	  if(s[i]!=' '){
		break
	  }	  
  }
  for ; i >=0; i--{
	if(s[i]!=' '){
		sum++
	}else{
		break
	}

  }
  return sum
}

func main(){
  str:="hello world"
  fmt.Println(str)
  fmt.Println(strings.Index(str, " "))
  fmt.Println(strings.Index(str, "X"))
  fmt.Println(len(str))
  fmt.Println(lengthOfLastWord(str))
  fmt.Println(lengthOfLastWord("a "))
  fmt.Println(lengthOfLastWord("a"))

}

