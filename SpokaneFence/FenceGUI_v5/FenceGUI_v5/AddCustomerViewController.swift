//
//  AddCustomerViewController.swift
//  FenceGUI_v5
//
//  Created by Tanner Orndorff on 7/18/18.
//  Copyright © 2018 Monocle Heads. All rights reserved.
//

import UIKit

class AddCustomerViewController: UIViewController {

   
    @IBOutlet var fname: UITextField!
    @IBOutlet var lname: UITextField!
    @IBOutlet var address: UITextField!
    @IBOutlet var city: UITextField!
    @IBOutlet var state: UITextField!
    @IBOutlet var zip: UITextField!
    @IBOutlet var email: UITextField!
    @IBOutlet var phone_num: UITextField!
    @IBOutlet weak var notes: UITextView!
    
    override func viewDidLoad() {
        super.viewDidLoad()

        // Do any additional setup after loading the view.
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
    
    @IBAction func createCustomer(_ sender: Any) {
        //create customer object with given data
        //change variables to correct type
        Business.AddCustomer(fname: fname.text!, lname: lname.text!, address: address.text!, email: email.text!, phone_num: phone_num.text!, notes: notes.text)
        //add customer object to business
        //clear field
        fname.text = ""
        lname.text = ""
        address.text = ""
        city.text = ""
        state.text = ""
        zip.text = ""
        email.text = ""
        phone_num.text = ""
        notes.text = "Notes"
        
        //persistant storage
        NSUserDefaultsManager.sychronize()
        performSegue(withIdentifier: "unwindhome", sender: self)
    }
    
    /*
    // MARK: - Navigation

    // In a storyboard-based application, you will often want to do a little preparation before navigation
    override func prepare(for segue: UIStoryboardSegue, sender: Any?) {
        // Get the new view controller using segue.destinationViewController.
        // Pass the selected object to the new view controller.
    }
    */

}
