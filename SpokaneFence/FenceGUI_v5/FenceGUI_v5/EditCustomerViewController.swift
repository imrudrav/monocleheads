//
//  EditCustomerViewController.swift
//  FenceGUI_v5
//
//  Created by Tanner Orndorff on 8/1/18.
//  Copyright © 2018 Monocle Heads. All rights reserved.
//

import UIKit

class EditCustomerViewController: UIViewController {

    var cus: Customer?
    @IBOutlet var fname: UITextField!
    @IBOutlet var lname: UITextField!
    @IBOutlet var address: UITextField!
    @IBOutlet var email: UITextField!
    @IBOutlet var phone_num: UITextField!
    @IBOutlet weak var notes: UITextView!
    
    override func viewDidLoad() {
        super.viewDidLoad()

        // Do any additional setup after loading the view.
    }
    
    override func viewDidAppear(_ animated: Bool) {
        fname.text = cus?.fname
        lname.text = cus?.lname
        address.text = cus?.address
        email.text = cus?.email
        phone_num.text = cus?.phone_num
        notes.text = cus?.notes
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
    // MARK: - Navigation
    
    @IBAction func saveChanges(_ sender: Any) {
        //create customer object with given data
        let c = Customer(id:(cus?.id)!, fname: fname.text!, lname: lname.text!, address: address.text!, email: email.text!, phone_num: phone_num.text!, notes: notes.text)
        //change variables to correct type
        //add customer object to business
        cus = c
        Business.UpdateCustomer(key: (cus?.id!)!, c: cus!)
        //persistant storage
        NSUserDefaultsManager.sychronize()
        //clear screen
        fname.text = ""
        lname.text = ""
        address.text = ""
        email.text = ""
        phone_num.text = ""
        notes.text = "Notes"
        performSegue(withIdentifier: "unwindinspect", sender: self)
    }
    
    override func prepare(for segue: UIStoryboardSegue, sender: Any?) {
        let inspectcustomer = segue.destination as! InspectCustomerViewController
        inspectcustomer.cus = cus
    }
    
    
}
