//
//  ViewController.swift
//  Night Porter
//
//  Created by Tanner Orndorff on 7/31/17.
//  Copyright © 2017 Monocle Heads. All rights reserved.
//

import UIKit

class ViewController: UIViewController {

    @IBAction func changeBackground(sender: Any) {
        view.backgroundColor = UIColor.darkGray
        //get all subviews
        let allSubviews = view.subviews
        
        for eachView in allSubviews {
            if eachView is UILabel {
                let mylabel = eachView as! UILabel
                mylabel.textColor = UIColor.lightGray
            }
        }
        
    }
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view, typically from a nib.
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }


}

