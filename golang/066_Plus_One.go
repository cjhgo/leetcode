package main

import "fmt"

//array to number +1 to array can not cope with big integer
//add one and judge carry flag
func plusOne(digits []int)[]int{
  var d_len = len(digits)
  digits[d_len-1]++
  var carry=false
  if digits[d_len-1] == 10 {
	digits[d_len-1] = 0
	carry=true
  }
  var i int
  for i = d_len-2; i >= 0; i--{
	if carry{
	  digits[i]++
	  if(digits[i] == 10){
		digits[i]=0
		carry=true
	  }else{
		break
	  }
	}	
  }  
  if carry && i == -1{
	digits=append([]int{1},digits...)
  }
  return digits
}

func main(){

  //123+1=124
  //19+1=20
  //99+1=100
  fmt.Println(plusOne([]int{1,2,3}))
  fmt.Println(plusOne([]int{1,9}))
  fmt.Println(plusOne([]int{1,9,9}))
  fmt.Println(plusOne([]int{7,2,8,5,0,9,1,2,9,5,3,6,6,7,3,2,8,4,3,7,9,5,7,7,4,7,4,9,4,7,0,1,1,1,7,4,0,0,6}))
  
}