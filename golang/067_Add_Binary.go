package main

import "fmt"

func carryAdd(a byte, b byte, carry byte) (byte,byte){
	var abc = a+b+carry
	if abc == 0{
		return 0,0
	}else if abc == 1{
		return 1,0
	}else if abc == 2{
		return 0,1
	}else if abc == 3{
		return 1,1
	}
	return 0,0
}

func addBinary(a string, b string) string {
	var res string=""
	bytea,byteb := []byte(a), []byte(b)
	lena,lenb := len(a),len(b)
	var carry,temp byte = 0,0
	for ai ,bi := lena-1, lenb -1;ai >= 0 || bi >= 0; {
		var va,vb byte
		va,vb=0,0
		if ai >= 0{
			va = bytea[ai]-48
		}
		if bi >= 0{
			vb = byteb[bi]-48
		}
		temp, carry = carryAdd(va,vb,carry)
		res = string(temp+48)+res
		fmt.Printf("%d %d %d %s\n\n", va, vb, carry, res)
		ai--
		bi--
	}
	if carry == 1{
		res = "1"+res
	}
	return res
}

func main(){
  fmt.Printf("\n res:\n%s\n",addBinary("111111001", "1001") 	)
  fmt.Println("1"+"0")
  var a byte = 1
  var b byte = 1
  var c byte = 1
  fmt.Println(a+b+c)
}