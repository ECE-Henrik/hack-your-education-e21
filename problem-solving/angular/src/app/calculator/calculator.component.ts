import { Component } from '@angular/core';
import { FormBuilder } from '@angular/forms';

@Component({
  selector: 'app-calculator',
  templateUrl: './calculator.component.html',
  styleUrls: ['./calculator.component.scss']
})
export class CalculatorComponent {

  states = ['ut', 'nv', 'tx', 'al' ,'ca']
  result = 0;

  form = this.fb.group({
    quantity: [''],
    price: [''],
    state: [''],
  }) 

  constructor(private fb: FormBuilder) { }

  calculate(quantity: number, price: number, state: string): number {  
    var sum = quantity * price;
    sum = this.calculateDiscount(sum);
    sum = this.calculateTax(sum, state);
    return sum
  }

  calculateTax(sum: number, state: string) {
    var tax = 0;

    if (state == "ut") {
        tax = sum*0.0685;
    }
    if (state == "nv") {
        tax = sum*0.08;
    }
    if (state == "tx") {
        tax = sum*0.0625;
    }
    if (state == "al") {
        tax = sum*0.04;
    }
    if (state == "ca") {
        tax = sum*0.0825;
    }

    return sum + tax;
}

calculateDiscount(sum: number) {
    var discount = 0;
    if (sum > 50000) {
        discount = (sum*0.15);
    }
    if (sum > 10000) {
        discount = (sum*0.1);
    }
    if (sum > 7000) {
        discount = (sum*0.07);
    }
    if (sum > 5000) {
        discount = (sum*0.05);
    }
    if (sum > 1000) {
        discount = (sum*0.03);
    }
    return sum - discount;
  }

  onSubmit() {
    this.result = this.calculate(this.form.value.quantity, this.form.value.price, this.form.value.state)
  }
}
